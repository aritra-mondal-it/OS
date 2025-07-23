/**********************************************************************************************************************************************************************
 * Assignment :- 4
 * Name :- Ansh Kumar Singh, Trisanjit Das, Aritra Mondal
 * Roll No. :- 002311001073, 002311001089, 002311001091
 * Sec. :- A2
 * Team No :- 04
 * Date :- 13/08/2025
 **********************************************************************************************************************************************************************
 * mmap and page fault
 **********************************************************************************************************************************************************************
 *
 * ASSIGNMENT DETAILS :
 * 
 * Objective of this programming assignment is to use mmap() call and
 * observe page-fault using the ‘sar’ command.
 * 
 * A big file (about 8GB) should be created using the ‘fallocate’ command.
 * This big file should be written with a single byte value (say X) at a specific
 * offset (say F). Both the values and the offset should be generated using a
 * random function. Please do remember this random function should
 * generate a quantity anywhere between 0 and 8G for the value of F and
 * between 0–255 for the value of X.
 * 
 * The above big file should also be mapped in the virtual address space
 * using mmap() call. Once it is mapped, the data should be read from the
 * same specific offset (F). Now, if the data read is X`; then verify that X and
 * X` are the same. In case of verification failure, an error message is to be
 * printed and also the program should terminate. Note that, the offset value F
 * can be anywhere between 0 and 8G and you should display the offset as
 * hex number format.
 * 
 * This sequence of writing and reading data to/from a specific offset and also
 * verification should be put in a while loop to go forever.
 * 
 * In another terminal execute the command ‘sar –B 1’ to observe for the
 * page fault. This command should be started before the above program is
 * put under execution. So, one can observe that the page faults are
 * increasing, once the above program starts executing.
 * 
 * The output of the program and the ‘sar’ command should be pasted as a
 * comment at the beginning of the program file as indicated by the
 * guidelines.
 * Objective:
 * To use the mmap() system call and monitor page faults using 'sar -B 1'. The program writes a random byte (X) at a random offset (F)
 * in a large file mapped via mmap, then verifies the byte through the mapped memory. This operation is repeated in a loop.
 *
 * Instructions:
 * 1. Run 'sar -B 1' in a separate terminal to observe page fault statistics.
 * 2. The program continuously:
 *    - Chooses random offset F ∈ [0, 8MB)
 *    - Chooses random byte X ∈ [0, 255]
 *    - Writes X at F using write()
 *    - Reads and verifies byte at F using mmap'd memory
 *    - Prints verification result
 *
 * Compilation: gcc A2_04_4.c -o A2_04_4
 * Execution: ./A2_04_4
 * 
 * 
 *
 **********************************************************************************************************************************************************************/


#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <errno.h>
#include <string.h>

#define FILE_SIZE 8388608  // 8 MB

int main() {
    srand(time(NULL)); // Seed RNG with current time

    // Open/Create file
    int fd = open("bigfile.dat", O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Allocate 8MB space using posix_fallocate
    if (posix_fallocate(fd, 0, FILE_SIZE) != 0) {
        perror("Error allocating file size");
        close(fd);
        return EXIT_FAILURE;
    }

    // Memory map the file
    uint8_t *mapped = mmap(NULL, FILE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped == MAP_FAILED) {
        perror("Error mapping file");
        close(fd);
        return EXIT_FAILURE;
    }

    while (1) {
        uint8_t X = rand() % 256;
        off_t F = rand() % FILE_SIZE;

        // Write to file at offset F
        if (lseek(fd, F, SEEK_SET) == (off_t)-1) {
            perror("Error seeking in file");
            break;
        }

        if (write(fd, &X, 1) < 0) {
            perror("Error writing to file");
            break;
        }

        // Verify using mapped memory
        uint8_t X_read = mapped[F];
        if (X != X_read) {
            fprintf(stderr, "Verification failed: X = %02x, X' = %02x at offset 0x%lx\n", X, X_read, (unsigned long)F);
            break;
        } else {
            printf("Verification success: X = %02x at offset 0x%lx\n", X, (unsigned long)F);
        }

        sleep(1); // Delay to help observe page faults
    }

    // Clean up
    munmap(mapped, FILE_SIZE);
    close(fd);

    return 0;
}
