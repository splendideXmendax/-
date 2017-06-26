#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include<pthread.h>
#include<ctype.h>

void* thread_func(void* ptr)
{
    int newfd = (int)(intptr_t)ptr;

    while(1)
    {
        char buf[1024];
        memset(buf, 0, sizeof(buf));
        read(newfd, buf, sizeof(buf));
        if(strcmp(buf, "HELLO") == 0)
        {
            write(newfd, "world", 5);
        }
        else if(strcmp(buf, "WORLD") == 0)
        {
            write(newfd, "hello", 5);
        }
        else
        {
            char* str = buf;
            for(; *str != '\0'; str++)
            {
                *str = toupper(*str);
            }
            write(newfd, buf, strlen(buf));
        }

    }
    close(newfd);
    return NULL;

}
int main()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    addr.sin_port = htons(8888);

    if(bind(fd, (struct sockaddr*)&addr, sizeof(addr)) != 0)
    {
        perror("bind");
        return 0;
    }
    printf("strat listen\n");

    listen(fd, 250);
    while(1)
    {
        int newfd = accept(fd, NULL, NULL);
        if(newfd < 0)
        {
            perror("accept");
            return 0;
        }
        printf("连接成功\n");

        pthread_t tid;
        pthread_create(&tid, NULL, thread_func, (void*)(intptr_t)newfd);
        pthread_detach(tid);
    
    }

    return 0;
}
#if 0

int myServer()
{

    int fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(9800);

    if(bind(fd, (struct sockaddr*)&addr, sizeof(addr)) != 0)
    {
        perror("bind");
        return 0;
    }
    printf("strat listen\n");

    listen(fd, 256);

    int newfd = accept(fd, NULL, NULL);
    if(newfd < 0)
    {
        perror("accept");
        return 0;
    }

    int bufsize = 0;
    socklen_t argsize = sizeof(bufsize);

    getsockopt(newfd, SOL_SOCKET, SO_RCVBUF, &bufsize, &argsize);
    printf("recv bufsize is %d\n", bufsize);
    getsockopt(newfd, SOL_SOCKET, SO_SNDBUF, &bufsize, &argsize);
    printf("send bufsize is %d\n", bufsize);

    int dev_fd = open("aaaa.c", O_WRONLY|O_CREAT, 0666);

    char buf[256] = { 0 };
    while(1)
    {
        int ret = read(newfd, buf, sizeof(buf));
        printf("ret = %d\n",ret);
        printf("%s\n",buf);
        if(ret <= 0)
        {
            printf("传输完毕\n");
            break;
        }
        write(dev_fd, buf, ret);
        printf("buf = %s\n", buf);

        memset(buf, 0, sizeof(buf));
    }

    close(newfd);
    close(fd);
    close(dev_fd);

    return 0;
}
int main()
{
    myServer();

    return 0;
}


































#endif
