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
        char buf[100];

        if (argc != 3) {
                printf("Usage: %s devname 1(2)\n",argv[0]);
                goto error;
        }
        devname = argv[1];

        fd = open(devname, O_RDWR);
        if (fd == -1) {
                perror("open error");
                goto error;
        }
        
        if (atoi(argv[2]) == 1) {
                ret = write(fd, "hello", sizeof("hello"));
                if (ret == -1) {
                        perror("write error");
                        goto error;
                }
        }
        if (atoi(argv[2]) == 2) {
                ret = read(fd, buf, sizeof(buf));
                if (ret == -1) {
                        perror("read error");
                        goto error;
                }
                
                printf("readbuf:%s\n", buf);
        }

        ret = close(fd);
        if (ret == -1) {
                perror("close error");
                goto error;
        }
        
error:

        return 0;
}
