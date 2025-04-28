#define _GNU_SOURCE
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int fd = open("my_file.txt", O_APPEND | O_LARGEFILE);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Write data to the end of the file
    int read = write(fd, "Hello, world!\n", 14);
    if (read != 14)
      printf("unable to write");

    close(fd);
    return 0;
}
