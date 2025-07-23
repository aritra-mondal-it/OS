


#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>/**********************************************************************************************************************************************************************
 * NAME     : Ansh Kumar Singh, Trisanjit Das, Aritra Mondal
 * ROLL NO  : 002311001073, 002311001089, 002311001091
 * SEC      : A2
 * TEAM NO  : 04
 * ASSIGN   : 2B
 * DATE     : 13/08/2025
 **********************************************************************************************************************************************************************
 * mmap and verification of random write/read offset using page-backed memory
 **********************************************************************************************************************************************************************
 *
 * ASSIGNMENT DETAILS:
 *
 * Objective of this programming assignment is to use mmap() call and
 * verify memory-mapped read/write integrity at random offsets.
 *
 * A big file (about 8GB) should be created using the ‘fallocate’ command.
 * This big file should be written with a single byte value (say X) at a specific
 * offset (say F). Both the values and the offset should be generated using a
 * random function. The random offset F should be anywhere between 0 and
 * 8GB, and X should be between 0–255.
 *
 * The big file is mapped into the virtual address space using mmap().
 * After mapping, data is read back from the same offset F. If the read value
 * (X`) differs from X, an error message is printed and the program terminates.
 * Otherwise, verification success is printed in hex offset format.
 *
 * This sequence is repeated in an infinite loop.
 *
 * Compilation Command:
 * gcc A2_04_2B.c -o A2_04_2B
 *
 * Execution Command:
 * ./A2_04_2B
 *
 * Sample Output:
 * --------------
 * Verification success: X = 91 at offset 0x2c6335
 * Verification success: X = 11 at offset 0x101c18
 * Verification success: X = 39 at offset 0x1f8add
 * Verification success: X = 47 at offset 0x2d86fa
 * Verification success: X = 8e at offset 0x1f1de3
 * Verification success: X = ed at offset 0x266148
 * Verification success: X = 46 at offset 0x15070a
 * Verification success: X = 06 at offset 0x3b02f2
 * Verification success: X = d6 at offset 0x518829
 * Verification success: X = 5f at offset 0xe1e6e
 * Verification success: X = 25 at offset 0x731503
 * Verification success: X = 74 at offset 0x3ce809
 * Verification success: X = d0 at offset 0x6427ef
 * Verification success: X = bb at offset 0x4721f1
 * Verification success: X = c7 at offset 0x7b1ca3
 * Verification success: X = 8f at offset 0x75b658
 * ^C
 *
 **********************************************************************************************************************************************************************/

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
