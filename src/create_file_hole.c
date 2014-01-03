/*
 * Create a file with void hole, which means that offset > file_length
 */

#include "../include/apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
    int fd;
    if ((fd = creat("file.hole", FILE_MODE)) < 0)
        printf("create error");
    if (write(fd, buf1, 10) != 10)
        printf("buf1 write error");
    // Create a file with buf1 string
    if (lseek(fd, 5, SEEK_SET) == -1) // here we set the SEEK_SET value  == 5
        printf("lseek error");
    if (write(fd, buf2, 10) != 10)
        printf("buf2 write error");
    // Continue to add a hold in this file
    exit(0);
}
