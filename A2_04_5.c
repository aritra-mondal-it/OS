/*
 * NAME - SUMIT DE
 * ROLL NO - 002211001109
 * SECTION - A2
 *
 * ASSIGNMENT - 5
 ***********************************************************************************************************************************************************
 * Thread, Synchronizations & Shared Memory
 ***********************************************************************************************************************************************************
 * ASSIGNMENT DETAILS -
 * Consider a main process which creates three threads Th1, Th2, and Th3. Main generates two random quantities (X, Y) < 10,
 * stores them in shared memory, and threads compute:
 *   Th1: A = X*Y, E = (X+Y)*(X-Y)
 *   Th2: B = (X*Y)/2, D = (X*Y)/(X+Y)
 *   Th3: C = X+Y
 * Shared memory created via shmget/shmat. All values stored per (X,Y) pair.
 * Program exits once all N pairs are processed; prints table at end.
 *
 * Use 'ipcs -m' to inspect shared memory.
 ***********************************************************************************************************************************************************
 * 
 * INPUT DESCRIPTION -
 *   User enters the number of (X,Y) pairs from CLI
 * OUTPUT DESCRIPTION -
 *   Prints computation stages and final table of X, Y, A, B, C, D, E
 ***********************************************************************************************************************************************************
 *
 * SAMPLE OUTPUT (truncated) -
 * Sample Output:
 * -------------------------------
 * Enter the number of pairs to generate:
 * 2
 * Creating threads...
 * Threads created
 * 
 * Main: Generating (X,Y) = (8.00, 1.00)
 * Thread 1: computing A = X*Y
 * Thread 2: computing B = (X*Y)/2
 * Thread 3: computing C = X+Y
 * Thread 2: computing D = (X*Y)/(X+Y)
 * Thread 1: computing E = (X+Y)*(X-Y)
 * 
 * Main: Generating (X,Y) = (2.00, 1.00)
 * Thread 1: computing A = X*Y
 * Thread 2: computing B = (X*Y)/2
 * Thread 3: computing C = X+Y
 * Thread 2: computing D = (X*Y)/(X+Y)
 * Thread 1: computing E = (X+Y)*(X-Y)
 * 
 *   ( X ,  Y ) :    A     B     C     D     E
 * 
 * (8.00, 1.00):   8.00   4.00   9.00   0.89  63.00
 * (2.00, 1.00):   2.00   1.00   3.00   0.67   3.00
 **********************************************************************************************************************************************************
*/

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
