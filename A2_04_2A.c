/**********************************************************************************************************************************************************************
 * Assignment :- 2A
 * Name :- Ansh Kumar Singh, Trisanjit Das, Aritra Mondal
 * Roll No. :- 002311001073, 002311001089, 002311001091
 * Sec. :- A2
 * Team No :- 04
 * Date :- 30/07/2025 

 **********************************************************************************************************************************************************************
 * IPC/SYNCHRONIZATION
 **********************************************************************************************************************************************************************
 *
 * Assignment Details - 
 * Catch the signal ‘SIGINT’ and display “Ha Ha, Not Stopping”. Use
‘signal’ system call. Always use “perror” to check the return status of
a library/system call.
 *
 * Input Description - 
 * Control + C
 *
 * Output Description - 
 * Ha Ha, Not Stopping
 *
 ***********************************************************************************************************************************************************************
 * Compilation Command - 
 * gcc A2_04_2A.c
 *
 * Execution Command - 
 * ./a.out
 *
 ***********************************************************************************************************************************************************************
 * Sample Input -
 * Ctrl + C
 *
 * Sample Output -
 * 
 * Program is running...
 * Program is running...
 * Program is running...
 * Program is running...
 * ^CHa Ha, Not Stopping
 * Program is running...
 * Program is running...
 * Program is running...
 * Program is running...
 * ^C
 * The program stops after then.
 **********************************************************************************************************************************************************************
 */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigint_handler(int signal) {
    printf("Ha Ha, Not Stopping\n");
}

int main() {
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    // Doing some work
    while (1) {
        printf("Program is running...\n");
        sleep(1);  // Sleep for a second before next iteration, to space out each iteration separately.
    }

    return 0;
}
