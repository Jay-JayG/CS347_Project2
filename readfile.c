#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {

    int fd = open(argv[1], O_RDONLY);

    if (fd == -1) {
        perror("open");
    }

    char buf[2048];
    int count;

    count = read(fd, buf, sizeof buf);

    write(1, buf, count);

    return 0;
}