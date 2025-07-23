/**********************************************************************************************************************************************************************
 * NAME     : Ansh Kumar Singh, Trisanjit Das, Aritra Mondal
 * ROLL NO  : 002311001073, 002311001089, 002311001091
 * SEC      : A2
 * TEAM NO  : 04
 * ASSIGNMDNT NO   : 6
 * DATE     : 03/09/2025
 **********************************************************************************************************************************************************************
 * ASSIGNMENT DETAILS :
 * The objective of this assignment is to use thread programming technique to
 * write a parallel program which will do Matrix Multiplication between two
 * large Square Matrices with unsigned character elements. You have to also
 * measure the time elapsed. The Matrix should be large enough (at least
 * 3000 x 3000) and dynamically allocated to fit in your computer memory.
 * Both the Matrices need to be initialized with random numbers (‘mod’ to
 * some value).
 * As you increase the number of threads (max to your number of CPUs), your
 * timing should show improvement. Use ‘gettimeofday’ to note down the
 * timing. Make sure you attach the timing to the starting comment block of
 * your source file. Your time should not include the Matrices initialization
 * time.
 * You have to use various ‘Pthread’ library calls to do this assignment
 * properly. Use the proper process listing command (ps) to show (and attach
 * it to the starting comment block of your source file) that your threads are
 * running in the system. Also, use proper command to show CPU
 * utilization (cpustat or sar) and attach these outputs to the starting comment
 * block of your source file.
 * This program should take four command line arguments. The first
 * argument is the dimension of the Square Matrix.
 * The second argument is about the number of threads. For example, the
 * value of the second argument will be 1, 2, 3, 4 etc.; signifying total no of
 * threads which will be created.
 * The third argument will be the value of the ‘mod’ which will be used to
 * initialize all the elements of two input square matrices.
 * The fourth (last) argument will be the print_switch. If its value is ‘1’, both the
 * Input and Output Matrices and as well as the Result Matrix will be printed
 * on the screen. In case the value is ‘0’, Matrices won’t be printed on the
 * screen.
 *
 * INPUT DESCRIPTION :
 * Command line arguments:
 * 1) Matrix dimension (N)
 * 2) Number of threads (T)
 * 3) Modulo value for initialization (mod)
 * 4) Print switch (1 to print matrices and result, 0 otherwise)
 *
 * OUTPUT DESCRIPTION :
 * Displays the time taken for matrix multiplication.
 * Prints matrices and result if print switch is set to 1.
 *
 * COMPILATION :
 * gcc A2_04_6.c -o A2_04_6
 * 
 * EXECUTION :
 * ./assignment6 <matrix_dimension> <num_threads> <mod> <print_switch>
 * Example: ./assignment6 3000 4 100 0
 *
 * SAMPLE INPUT :
 * gcc A2_04_6.c -o A2_04_6 && 
 * ./A2_04_6 3000 4 100 0
 *
 * SAMPLE OUTPUT :
 * Time taken for multiplication (in microseconds): 32811973
 *
 **********************************************************************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

unsigned char **matA, **matB, **matC;
int size, n_threads;

typedef struct {
    int tid;
    int start_row;
    int end_row;
} thread_arg;

void *multiply(void *arg) {
    thread_arg *t = (thread_arg *)arg;
    for (int i = t->start_row; i < t->end_row; i++) {
        for (int j = 0; j < size; j++) {
            unsigned int sum = 0;
            for (int k = 0; k < size; k++) {
                sum += matA[i][k] * matB[k][j];
            }
            matC[i][j] = sum % 256; // wrap to 0-255
        }
    }
    return NULL;
}

unsigned char **allocate_matrix(int n) {
    unsigned char **mat = (unsigned char **)malloc(n * sizeof(unsigned char *));
    for (int i = 0; i < n; i++) {
        mat[i] = (unsigned char *)malloc(n * sizeof(unsigned char));
    }
    return mat;
}

void fill_matrix(unsigned char **mat, int n, int mod) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = rand() % mod;
}

void print_matrix(unsigned char **mat, int n, const char *name) {
    printf("\nMatrix %s:\n", name);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%3d ", mat[i][j]);
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <size> <n_threads> <mod> <print_switch>\n", argv[0]);
        return 1;
    }

    size = atoi(argv[1]);
    n_threads = atoi(argv[2]);
    int mod = atoi(argv[3]);
    int print_switch = atoi(argv[4]);

    matA = allocate_matrix(size);
    matB = allocate_matrix(size);
    matC = allocate_matrix(size);

    srand(time(NULL));
    fill_matrix(matA, size, mod);
    fill_matrix(matB, size, mod);

    pthread_t threads[n_threads];
    thread_arg args[n_threads];

    int rows_per_thread = size / n_threads;
    int extra = size % n_threads;

    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Creating threads
    for (int i = 0; i < n_threads; i++) {
        args[i].tid = i;
        args[i].start_row = i * rows_per_thread + (i < extra ? i : extra);
        args[i].end_row = args[i].start_row + rows_per_thread + (i < extra ? 1 : 0);
        pthread_create(&threads[i], NULL, multiply, &args[i]);
    }

    // Joining threads
    for (int i = 0; i < n_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    gettimeofday(&end, NULL);
    long elapsed = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);

    if (print_switch) {
        print_matrix(matA, size, "A");
        print_matrix(matB, size, "B");
        print_matrix(matC, size, "C");
    }

    printf("\nTime taken for multiplication (in microseconds): %ld\n", elapsed);

    // Free memory
    for (int i = 0; i < size; i++) {
        free(matA[i]);
        free(matB[i]);
        free(matC[i]);
    }
    free(matA); free(matB); free(matC);

    return 0;
}