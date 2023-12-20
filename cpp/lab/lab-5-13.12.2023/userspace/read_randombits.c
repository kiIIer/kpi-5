#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int fd;
    ssize_t bytes_read;
    int num_ints, i;
    int *buffer;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <num_ints>\n", argv[0]);
        return -1;
    }

    num_ints = atoi(argv[1]);
    buffer = malloc(num_ints * sizeof(int));
    if (!buffer) {
        perror("Failed to allocate memory");
        return -2;
    }

    fd = open("/dev/randombits", O_RDONLY);
    if (fd < 0) {
        perror("Failed to open the device");
        free(buffer);
        return -3;
    }

    bytes_read = read(fd, buffer, num_ints * sizeof(int));
    if (bytes_read < 0) {
        perror("Failed to read from the device");
        close(fd);
        free(buffer);
        return -4;
    }

    printf("Read %ld bytes. Integers:\n", bytes_read);
    for (i = 0; i < num_ints; i++) {
        printf("%d\n", buffer[i]);
    }

    close(fd);
    free(buffer);
    return 0;
}

