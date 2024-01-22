#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        while (1) {
            char buf[2048];
            int count;

            // Case nothing to print
            count = read(0, buf, 2048);
            if (count == 0) {
                return 0;
            }
            write(1, buf, count);
        }
    }
    
    else {
        for (int i = 1; i < argc; i++) {

        }
    }

    return 0;
}