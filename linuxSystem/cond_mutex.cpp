#include<iostream>
#include"../header.h"
#include<pthread.h>
#include<list>
#include<sys/socket.h>
using namespace std;
//任务参数
typedef struct Task
{
    int a;
} Task;



list<Task*> *tasks_send;
list<Task*> *tasks_recv;

int fd[2];
int f_pipe[2];

void* send_thread(void* ptr)
{
    int i = 0;
    while(1)
    {

        char buf;
        //如果没有数据 那么read 会阻塞
        read(fd[0], &buf, 1);

        if(buf == 1)
        {
            Task* t = new Task;
            t->a = i++;
            tasks_send->push_back(t); //插入
        }
        else if(buf == 2)
        {
            //交换队列
            list<Task*>* tmp = tasks_send;
            tasks_send = tasks_recv;
            tasks_recv = tmp;
            write(f_pipe[1], &buf, 1);
        }
    }

}
void* recv_thread(void* ptr)
{
    Task* t;

    while(1)
    {
        if(tasks_recv->size() == 0)
        {
            //通知生产者去交换
            //休眠
            char buf = 2;
            write(fd[1], &buf, 1);
            
            read(f_pipe[0], &buf, 1);


            continue ;
        }
        t = *tasks_recv->begin();  //拿出链表头
        tasks_recv->pop_front();  //删除

        printf("t->task is %d\n", t->a);
        delete t;  //销毁 new delete 还是线程安全
    }
}

int main()
{
    tasks_send = new list<Task*>;
    tasks_recv = new list<Task*>; 



    pthread_t tid_s, tid_r;
    pipe(f_pipe);


    socketpair(AF_UNIX, SOCK_STREAM, 0, fd);
    pthread_create(&tid_s, NULL, send_thread, NULL);
    pthread_create(&tid_r, NULL, recv_thread, NULL);


    while(1)
    {
        int ret =getchar();
        char buf = 1;
        write(fd[1], &buf, 1);
    }




    pthread_join(tid_s, NULL);
    pthread_join(tid_r, NULL);

    return 0;
}
