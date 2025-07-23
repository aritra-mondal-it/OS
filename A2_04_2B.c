/**********************************************************************************************************************************************************************
 * Assignment :- 2B
 * Name :- Ansh Kumar Singh, Trisanjit Das, Aritra Mondal
 * Roll No. :- 002311001073, 002311001089, 002311001091
 * Sec. :- A2
 * Team No :- 04
 * Date :- 30/07/2025
 ***********************************************************************************************************************************************************************
 * IPC/SYNCHRONIZATION -IPC using Named Pipe (FIFO)
 ***********************************************************************************************************************************************************************
 *
 * Assignment Details -
 * Create two processes, named Proc1 and Proc2. Transfer 1GB file from Proc1 to Proc2 using a FIFO. Now, transfer the same file from Proc2 to Proc1 using another FIFO. Now, compare the two files to make sure that the same file has returned back. Also, print the time required to do this double transfer. Attach this output to the source file as a comment.
 * To create FIFO, you can either use shell command or system call.
 * To create a large file you can use the relevant command.
 * Use ‘ls –l’ command to show the FIFO and the large file. Attach this output to the source file as a comment.
 * Make sure that the starting comment block has all the necessary information attached.
 *
 * Input Description -
 * No input
 *
 * Output Description -
 * The RTT (Round trip time gets reported in seconds).
 *
 ***********************************************************************************************************************************************************************
 *
 * Sample Input -
 * No input
 *
 * Sample Output -
 * FIFO fifo1 already exists.
 * FIFO fifo2 already exists.
 * Time taken for the double transfer: 0.025728 seconds
 * Files are identical
 *
 * --- ls -l output ---
 * prw-r--r--. 1 aritra users       0 Jul 23 22:49 fifo1
 * prw-r--r--. 1 aritra users       0 Jul 23 22:49 fifo2
 * -rw-r--r--. 1 aritra users 1048576 Jul 23 22:48 largefile
 * -rw-r--r--. 1 aritra users 1048576 Jul 23 22:49 largefile_copy_back
 *
 ***********************************************************************************************************************************************************************
 * Creation of 1GB file
 *
 * $ dd if=/dev/urandom of=largefile bs=1M count=1024
 * dd: error writing ‘largefile’: Disk quota exceeded
 * 39+0 records in
 * 38+0 records out
 * 39903232 bytes (40 MB) copied, 5.00468 s, 8.0 MB/s
 * $ ls
 * fifo1  fifo2  largefile
 * $ rm largefile
 * $ dd if=/dev/urandom of=largefile bs=1M count=1
 * 1+0 records in
 * 1+0 records out
 * 1048576 bytes (1.0 MB) copied, 0.15 s, 6.9 MB/s
 *
 * Displaying list of files to verify
 *
 * $ ls -l fifo1 fifo2 largefile
 * prw-r--r--. 1 aritra users       0 Jul 23 22:48 fifo1
 * prw-r--r--. 1 aritra users       0 Jul 23 22:48 fifo2
 * -rw-r--r--. 1 aritra users 1048576 Jul 23 22:48 largefile
 *
 **********************************************************************************************************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void create_fifo(const char *fifo_name)
{
    if (access(fifo_name, F_OK) == -1)
    {
        if (mkfifo(fifo_name, 0666) == -1)
        {
            perror("mkfifo");
            exit(1);
        }
    }
    else
    {
        printf("FIFO %s already exists.\n", fifo_name);
    }
}

void write_to_fifo(const char *input_file, const char *fifo_name)
{
    int fifo_fd = open(fifo_name, O_WRONLY);
    if (fifo_fd == -1)
    {
        perror("open fifo for writing");
        exit(1);
    }

    int input_fd = open(input_file, O_RDONLY);
    if (input_fd == -1)
    {
        perror("open input file");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0)
    {
        write(fifo_fd, buffer, bytes_read);
    }

    close(input_fd);
    close(fifo_fd);
}

void read_from_fifo(const char *output_file, const char *fifo_name)
{
    int fifo_fd = open(fifo_name, O_RDONLY);
    if (fifo_fd == -1)
    {
        perror("open fifo for reading");
        exit(1);
    }

    int output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (output_fd == -1)
    {
        perror("open output file");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = read(fifo_fd, buffer, BUFFER_SIZE)) > 0)
    {
        write(output_fd, buffer, bytes_read);
    }

    close(fifo_fd);
    close(output_fd);
}

int compare_files(const char *file1, const char *file2)
{
    int fd1 = open(file1, O_RDONLY);
    int fd2 = open(file2, O_RDONLY);
    if (fd1 == -1 || fd2 == -1)
    {
        perror("open compare files");
        exit(1);
    }

    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    ssize_t b1, b2;
    while ((b1 = read(fd1, buffer1, BUFFER_SIZE)) > 0 &&
        (b2 = read(fd2, buffer2, BUFFER_SIZE)) > 0)
    {
        if (b1 != b2 || memcmp(buffer1, buffer2, b1) != 0)
        {
            close(fd1);
            close(fd2);
            return 0;
        }
    }

    close(fd1);
    close(fd2);
    return 1;
}

int main()
{
    struct timeval start, end;
    double elapsed;

    create_fifo("fifo1");
    create_fifo("fifo2");

    gettimeofday(&start, NULL);

    pid_t p1 = fork();
    if (p1 == -1)
    {
        perror("fork 1");
        exit(1);
    }
    else if (p1 == 0)
    {
        write_to_fifo("largefile", "fifo1");
        read_from_fifo("largefile_copy", "fifo2");
        exit(0);
    }

    pid_t p2 = fork();
    if (p2 == -1)
    {
        perror("fork 2");
        exit(1);
    }
    else if (p2 == 0)
    {
        read_from_fifo("largefile_copy_back", "fifo1");
        write_to_fifo("largefile_copy_back", "fifo2");
        exit(0);
    }

    waitpid(p1, NULL, 0);
    waitpid(p2, NULL, 0);

    gettimeofday(&end, NULL);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;

    printf("Time taken for the double transfer: %.6f seconds\n", elapsed);

    if (compare_files("largefile", "largefile_copy"))
    {
        printf("Files are identical\n");
    }
    else
    {
        printf("Files are not identical\n");
    }

    printf("\n--- ls -l output ---\n");
    system("ls -l largefile largefile_copy_back fifo1 fifo2");

    return 0;
}
