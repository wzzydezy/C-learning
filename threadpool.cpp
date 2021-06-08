
#include <iostream>
#include <pthread.h>
#include <exception>
#include <mutex>
#include "windows.h"

class threadpool
{
public:
    threadpool(int thread_num=8);
    ~threadpool();
private:
    static void* worker(void* arg);
    void run();

private:
    int m_thread_num;
    pthread_t* m_threads;
    std::mutex mtx;
};

threadpool::threadpool(int thread_num): m_thread_num(thread_num)
{
    if(thread_num<=0)
        throw std::exception();
    m_threads = new pthread_t[m_thread_num];
    if(!m_threads)
        throw std::exception();
    for(int i=0; i<thread_num; i++){
        if( pthread_create(m_threads + i, NULL, worker, this) != 0){
            delete[] m_threads;
            throw std::exception();
        }
        if(pthread_detach(m_threads[i])){
            delete[] m_threads;
            throw std::exception();
        }
    }
}

threadpool::~threadpool()
{
    delete[] m_threads;
}

void* threadpool::worker(void* arg)
{
    threadpool* pool = (threadpool *) arg;
    pool->run();
    return pool;
}

void threadpool::run()
{
    int id = GetCurrentThreadId();
    //while(1)
       mtx.lock();
       std::cout<< id << std::endl;
       mtx.unlock();
       return;
}

int main()
{
    threadpool* m_pool = new threadpool(0);
    return 0;
}

