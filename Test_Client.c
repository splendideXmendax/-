#include<sys/socket.h>
#include<netinet/in.h>
#include<signal.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    signal(SIGPIPE, SIG_IGN);
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("192.168.184.137");
    addr.sin_port = htons(8888);

    if(connect(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1)
    {
        perror("connect");
        return 0;
    }
    char buf[50] = { 0 };
    char buf1[60] = { 0 };
    while(1)
    {

        scanf("%s",buf);
        write(fd, buf, strlen(buf));
        read(fd, buf1, sizeof(buf1));
        printf("%s\n", buf1);
        memset(buf, 0, sizeof(buf));
        memset(buf1, 0, sizeof(buf1));
    }
    return 0;

}

