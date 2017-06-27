#include<iostream>
#include"../header.h"
#include<list>
#include<pthread.h>
//任务参数
//
//
//
using namespace std;

typedef struct Task
{

    int a;
}Task;


list<int > aaa;
list<Task*> tasks;

pthread_mutex_t mutex;

//定义条件变量
pthread_cond_t cond;

class AutoLock
{
public:
    AutoLock(pthread_mutex_t& mutex) : mutex(mutex)
    {
        pthread_mutex_lock(&mutex);
    }
    ~AutoLock()
    {
        pthread_mutex_unlock(&mutex);
    }
    pthread_mutex_t& mutex;

};



void* send_thread(void* ptr)
{
    char buf = 1;
    int i = 0;
    printf("-----------send_thread\n");
    while(1)
    {
        usleep(100*1000);
        getchar();
        Task* t = new Task;
        t->a = i++;
        {

            AutoLock lock(mutex);
            tasks.push_back(t); //插入
            //唤醒 pthread_cond_wait的线程
            pthread_cond_signal(&cond);
        }
    }

}
void* recv_thread(void* ptr)
{
    Task *t;
    printf("-------------recv_thread\n");
    while(1)
    {
        //等待条件变量
        pthread_mutex_lock(&mutex);
        //要一把锁来配合
        pthread_cond_wait(&cond, &mutex);

        /* 这些代码需要加锁
         *
         * pthread_mutex_unlock(&mutex);
         * wait ....
         * pthread_mutex_lock(&mutex);
         *
         */ 
        pthread_mutex_unlock(&mutex);
        {
            AutoLock lock(mutex);
            if(tasks.size() == 0) continue; 
            t = *tasks.begin();  //拿出链表头
            tasks.pop_front();  //删除
        }
        printf("t->task is %d\n", t->a);
        delete t;  //销毁 new delete 还是线程安全
    }
}

int main()
{

    //初始化条件变量
    pthread_cond_init(&cond, NULL);


    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutex, &attr);

    pthread_t tid_s, tid_r;

    pthread_create(&tid_s, NULL, send_thread, NULL);
    pthread_create(&tid_r, NULL, recv_thread, NULL);







    pthread_join(tid_s, NULL);
    pthread_join(tid_r, NULL);

    return 0;
}
