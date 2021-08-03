#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
        int ret = 0;
        int fd = 0;
        char *devname = NULL;
        char buf[BUFSIZ];

        if (argc != 2) {
                printf("Usage: %s devname\n",argv[1]);
                goto error;
        }
        devname = argv[1];

        fd = open(devname, O_RDWR);
        if (fd == -1) {
                perror("open error");
                goto error;
        }
        
        ret = write(fd, "hello", sizeof("hello"));
        if (ret == -1) {
                perror("write error");
                goto error;
        }

        ret = read(fd, buf, sizeof(buf));
        if (ret == -1) {
                perror("read error");
                goto error;
        }

        ret = close(fd);
        if (ret == -1) {
                perror("close error");
                goto error;
        }
        
error:

        return 0;
}
