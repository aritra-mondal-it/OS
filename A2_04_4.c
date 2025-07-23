/**********************************************************************************************************************************************************************
 * Assignment :- 2B
 * Name :- Ansh Kumar Singh, Trisanjit Das, Aritra Mondal
 * Roll No. :- 002311001073, 002311001089, 002311001091
 * Sec. :- A2
 * Team No :- 04
 * Date :- 13/08/2025
 **********************************************************************************************************************************************************************
 * mmap and page fault
 **********************************************************************************************************************************************************************
 *
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
 * Compilation: gcc assignment2B.c -o assignment2B
 * Execution: ./assignment2B
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
