/*
 * This function could check the STDIN is could be setted its offset or not
 */
#include "../include/apue.h"

int main(void)
{
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        printf("cannot seek\n");
    else
        printf("seek OK\n");
    exit(0);
}
