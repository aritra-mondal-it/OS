/**********************************************************************************************************************************************************************
 * NAME         : Ansh Kumar Singh, Trisanjit Das, Aritra Mondal
 * ROLL NO      : 002311001073, 002311001089, 002311001091
 * SEC          : A2
 * TEAM NO      : 04
 * ASSIGNMENT   : 5
 * DATE         : 20/08/2025
 ***********************************************************************************************************************************************************************
 * Thread, Synchronizations & Shared Memory
 ***********************************************************************************************************************************************************************
 *
 * ASSIGNMENT DETAILS:
 * 
 * Consider a main process which creates three threads Th1, Th2, and Th3. The main
 * process also creates two random quantities (X, Y), both less than 10. These two
 * values will be placed by the main process in the shared memory (One variant of IPC
 * Primitive) that is accessible by all the three threads Th1, Th2 and Th3. The shared
 * memory will be created by the main process using shmat/shmget calls.
 * For each pair of values (X,Y), it is required that some computations will be done by
 * various threads. The thread Th1 will compute A (X*Y) and the thread Th2 will
 * compute B (X*Y)/2). Similarly, Th3 computes C (X+Y), Th2 again computes D
 * ((X*Y)/(X+Y)), and finally Th1 computes E ((X+Y)(X-Y)). All these values are kept in
 * the shared memory in a tabular fashion as shown below.
 * The number of (X,Y) pairs will be taken as an argument from the CLI. It is the
 * responsibility of the main process to populate required numbers of (X,Y)s in the
 * shared memory. The program will only exit when all A,B,C etc. are computed for all
 * given (X,Y) values. Before exiting, all (X,Y)s, As, Bs etc. should be displayed.
 * Whenever, the threads complete one phase of computations (A, B, C, D and E), they
 * will go for another pair of (X,Y) values; but they will start all together. This can be
 * achieved by proper synchronization.
 * Use the proper shell command(ipcs) to display the Shared Memory
 * Status/Info/Statistics and attach this sample output as a comment.
 * 
 * Example:—
 *
 * Input: N, number of random pairs
 * Output Format:
 * Pairs(X,Y) | A | B | C | D | E
 * ——————————————————————————
 * (1, 2)     | 2 | 1 | 3 | .66 | -3
 * ——————————————————————————
 * (4, 1)     | 4 | 2 | 5 | .8  | 15
 * .........
 **********************************************************************************************************************************************************************
 * INPUT DESCRIPTION:
 *     Command line argument: N — the number of (X, Y) random pairs to be generated.
 * 
 * OUTPUT DESCRIPTION:
 *     Displays the computed values A, B, C, D, and E for each (X, Y) pair in a formatted table.
 * 
 * COMPILATION:
 *     gcc -o A2_04_5 A2_04_5.c -lpthread -lm
 * 
 * EXECUTION:
 *     ./A2_04_5 <number_of_pairs>
 * 
 * SAMPLE OUTPUT:
 *     Creating threads...
 *     Threads created
 *     Main: Generating (X,Y) = (8.00, 1.00)
 *     Thread 1: computing A = X*Y
 *     Thread 2: computing B = (X*Y)/2
 *     Thread 3: computing C = X+Y
 *     Thread 2: computing D = (X*Y)/(X+Y)
 *     Thread 1: computing E = (X+Y)*(X-Y)
 * 
 *     ( X ,  Y ) :    A     B     C     D     E
 *     (8.00, 1.00):   8.00   4.00   9.00   0.89  63.00
 *     (2.00, 1.00):   2.00   1.00   3.00   0.67   3.00
 * 
 * SHARED MEMORY INSPECTION:
 *     Use the command: ipcs -m
 **********************************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>

#define MAX_PAIRS 100
#define SHM_KEY 0x9999

typedef struct {
    float X, Y, A, B, C, D, E;
} PairData;

PairData *shm_ptr;
int total_pairs, current_index = 0;
int current_stage = 0; // 0: main -> 1..5 threads -> loop

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Th1: stages 1 (A) and 5 (E)
void* thread1(void* _) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (current_stage != 1 && current_stage != 5 && current_index < total_pairs)
            pthread_cond_wait(&cond, &mutex);
        if (current_index >= total_pairs) { pthread_mutex_unlock(&mutex); break; }

        if (current_stage == 1) {
            printf("Thread 1: computing A = X*Y\n");
            shm_ptr[current_index].A = shm_ptr[current_index].X * shm_ptr[current_index].Y;
        } else {
            printf("Thread 1: computing E = (X+Y)*(X-Y)\n");
            float x = shm_ptr[current_index].X, y = shm_ptr[current_index].Y;
            shm_ptr[current_index].E = (x + y) * (x - y);
        }
        current_stage++;
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

// Th2: stages 2 (B) and 4 (D)
void* thread2(void* _) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (current_stage != 2 && current_stage != 4 && current_index < total_pairs)
            pthread_cond_wait(&cond, &mutex);
        if (current_index >= total_pairs) { pthread_mutex_unlock(&mutex); break; }

        if (current_stage == 2) {
            printf("Thread 2: computing B = (X*Y)/2\n");
            shm_ptr[current_index].B = (shm_ptr[current_index].X * shm_ptr[current_index].Y)/2;
        } else {
            printf("Thread 2: computing D = (X*Y)/(X+Y)\n");
            float x = shm_ptr[current_index].X, y = shm_ptr[current_index].Y;
            shm_ptr[current_index].D = (x*y)/(x+y);
        }
        current_stage++;
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

// Th3: stage 3 (C)
void* thread3(void* _) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (current_stage != 3 && current_index < total_pairs)
            pthread_cond_wait(&cond, &mutex);
        if (current_index >= total_pairs) { pthread_mutex_unlock(&mutex); break; }

        printf("Thread 3: computing C = X+Y\n");
        shm_ptr[current_index].C = shm_ptr[current_index].X + shm_ptr[current_index].Y;

        current_stage++;
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    printf("Enter the number of pairs to generate:\n");
    scanf("%d", &total_pairs);
    if (total_pairs <= 0 || total_pairs > MAX_PAIRS) total_pairs = MAX_PAIRS;

    int shmid = shmget(SHM_KEY, sizeof(PairData)*MAX_PAIRS, IPC_CREAT | 0666);
    if (shmid < 0) { perror("shmget"); exit(1); }
    shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (void*)-1) { perror("shmat"); exit(1); }

    pthread_t t1, t2, t3;
    printf("Creating threads...\n");
    pthread_create(&t1, NULL, thread1, NULL);
    sleep(1);
    pthread_create(&t2, NULL, thread2, NULL);
    sleep(1);
    pthread_create(&t3, NULL, thread3, NULL);
    sleep(1);
    printf("Threads created\n\n");

    srand(time(NULL));

    for (current_index = 0; current_index < total_pairs; current_index++) {
        pthread_mutex_lock(&mutex);
        float x = rand() % 10, y = rand() % 10;
        shm_ptr[current_index].X = x;
        shm_ptr[current_index].Y = y;
        printf("Main: Generating (X,Y) = (%.2f, %.2f)\n", x, y);

        current_stage = 1;
        pthread_cond_broadcast(&cond);

        while (current_stage <= 5) pthread_cond_wait(&cond, &mutex);
        pthread_mutex_unlock(&mutex);
        printf("\n");
    }

    pthread_mutex_lock(&mutex);
    current_index = total_pairs;
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("  ( X ,  Y ) :    A     B     C     D     E\n\n");
    for (int i = 0; i < total_pairs; i++) {
        printf("(%.2f, %.2f): %6.2f %6.2f %6.2f %6.2f %6.2f\n",
            shm_ptr[i].X, shm_ptr[i].Y,
            shm_ptr[i].A, shm_ptr[i].B,
            shm_ptr[i].C, shm_ptr[i].D,
            shm_ptr[i].E);
    }

    shmdt(shm_ptr);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
