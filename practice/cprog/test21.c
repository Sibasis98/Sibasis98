#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#define GIGABYTE (1024 * 1024 * 1024)
#define MEGABYTE (1024 * 1024)

int main() {
    // ... (code to create memory-mapped file as before)
    int fd;
    void *ptr;

    // Create a temporary file of 1GB size
    fd = open("tempfile", O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Truncate the file to 1GB
    if (ftruncate(fd, GIGABYTE) == -1) {
        perror("ftruncate");
        exit(1);
    }

    // Memory map the file
    ptr = mmap(NULL, GIGABYTE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    char *data = (char *)ptr;

    // Access data in chunks to improve residency
    const int chunk_size = 10 * MEGABYTE; // Adjust chunk size as needed
    for (int i = 0; i < GIGABYTE; i += chunk_size) {
        // Process data in the chunk
        for (int j = 0; j < chunk_size; j++) {
          data[i] = 'x';
          sleep(1);
        }
    }

    // Unmap the memory
    if (munmap(ptr, GIGABYTE) == -1) {
        perror("munmap");
        exit(1);
    }

    // Close the file
    close(fd);

    return 0;
}
