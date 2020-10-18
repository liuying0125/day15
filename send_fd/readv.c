#include <func.h>

int main(int argc,char* argv[])
{
    int ret;
    ARGS_CHECK(argc,2);
    int fd = open(argv[1],O_RDWR);
    ERROR_CHECK(ret,-1,"open");
    char buf1[10]={0},buf2[10]={0};
    struct iovec iov[2];
    iov[0].iov_base = buf1;
    iov[0].iov_len = 2;
    iov[1].iov_base = buf2;
    iov[1].iov_len = 9;

    readv(fd,iov,2);
    printf("%s\n",buf1);
    printf("%s\n",buf2);
    close(fd);
    return 0;
}

