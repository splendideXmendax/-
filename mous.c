#include "../header.h"
#if 0
int main()
{
    int fd_key = open("/dev/input/event1", O_RDONLY);

    
    int fd = open("/dev/input/mice", O_RDONLY);
    int ret;
    char buf[8];
    char key[1024];


    while(1)
    {
        //阻塞
        int ret = read(fd, buf, sizeof(buf));

        printf("0x%2x, 0x%02x, 0x%02x\n",
                (unsigned char)buf[0],
                (unsigned char)buf[1],
                (unsigned char)buf[2]
                );
        ret = read(fd_key, key, sizeof(key));
        printf("recv key ... ret = %d\n", ret);
    }

}
#endif
#include<pthread.h>

void* key_thread(void *ptr)
{
    char key[1024];
    int fd_key = open("/dev/input/event1", O_RDONLY);

    while(1)
    {
        int ret = read(fd_key, key, sizeof(key));
        printf("recv key ... ret = %d\n", ret);
    }
}
void* mice_thread(void *ptr)
{
    char buf[8];
    int fd_mice = open("/dev/input/mice", O_RDONLY);
    while(1)
    {
        int ret = read(fd_mice, buf, sizeof(buf));
        printf("0x%02x, 0x%02x, 0x%02x\n",
                (unsigned char) buf[0],
                (unsigned char) buf[1],
                (unsigned char) buf[2]
                );
    }

}
int main()
{
    pthread_t tid_key, tid_mice;
    pthread_create(&tid_key, NULL, key_thread, NULL);
    pthread_create(&tid_mice, NULL, mice_thread, NULL);


    pthread_join(tid_key, NULL);
    pthread_join(tid_mice, NULL);
}
