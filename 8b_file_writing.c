/*
 * C program to create a file with 16 bytes of arbitrary data from the
 * beginning and another 16 bytes of arbitrary data from an offset of 48.
 * Display the file contents to demonstrate how the hole in file is handled.
 */

#include <fcntl.h>

int main(void) {
    char buf1[] = "123456789abcdefg";
    char buf2[] = "hijklmnopqrstuvw";

    int fd;
    fd = creat("t.txt", O_WRONLY | 777);
    write(fd, buf1, 16);
    lseek(fd, 48, SEEK_SET);
    write(fd, buf2, 16);
    close(fd);
    system("od -c t.txt");

    return 0;
}