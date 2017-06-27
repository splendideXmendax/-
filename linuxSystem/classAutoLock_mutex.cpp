#include"../header.h"
#include<pthread.h>
int a = 0;
pthread_mutex_t mutex;// 静态锁初始化

class AutoLock
{
public:
    AutoLock(pthread_mutex_t& m) : mutex(m)
    {
    
        pthread_mutex_lock(&mutex);
    }
    ~AutoLock()
    {
        printf("~Auto Lock  \n");
        pthread_mutex_unlock(&mutex);
    }

    pthread_mutex_t& mutex;
};
void add()
{
    AutoLock lock(mutex);
    if(a >= 100)
    {
        return ;
    }
    a++;
}
void* thread_func(void* ptr)
{
    sleep(1);
    int i;
    for(i = 0; i < 10; ++i)
    {
        add();
    }
}
int main()
{
    int i;
    pthread_t tid;
    //设置循环锁属性
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutex, &attr);

    pthread_create(&tid, NULL, thread_func, NULL);
    
    for(i = 0; i < 10; ++i)
    {
        {        
            AutoLock lock2(mutex);
            a++;
        }
    }
    printf("-----------\n");
    {

        AutoLock lock1(mutex);
        int b;
        b = 1;
    }

    printf("-----------\n");
  //  pthread_join(tid, NULL);
    printf("a is %d \n", a); // 200000

    return 0;
}
