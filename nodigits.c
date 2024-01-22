#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
# define BUFFER_SIZE 2048

int main(int argc, char *argv[]) {

    char buf[BUFFER_SIZE];
    char bufout[BUFFER_SIZE];
    int count;
    int df;

    if (argc < 2) {
        while (1) {
            count = read(0, buf, BUFFER_SIZE);
            if (count == 0) {
                return 0;
            }
            for (int i = 0, x = 0; i < count; i++) {
                if (!isdigit(buf[i])) {
                    bufout[x] = buf[i];
                    x++;
                }
            }
            write(1, bufout, strlen(bufout));
        }
    }
    
    else {
        for (int i = 1; i < argc; i++) {
            df = open(argv[i], O_RDONLY);
            if (df == -1) {
                perror("open");
                return 1;
            }
            while (1) {
                count = read(df, buf, BUFFER_SIZE);
                if (count == 0) {
                    close(df);
                    break;
                }
                for (int i = 0, x = 0; i < count; i++) {
                    if (!isdigit(buf[i])) {
                        bufout[x] = buf[i];
                        x++;
                    }
                }
                write(1, bufout, strlen(bufout));
            }
        }
    }
    return 0;
}