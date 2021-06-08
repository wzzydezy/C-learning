#define _CRTDBG_MAP_ALLOC 
#include <iostream>
#include <pthread.h>
#include <mutex>
#include <string>
#include <crtdbg.h>
#include <stdlib.h>


using namespace std;
string s;
mutex mtx;
bool stop = false;
static int num = 0;
static void *work1(void* args){
     while(num){
           if(mtx.try_lock()){
               int len = s.size();
               if(len % 4 == 0){
                   s += 'A';
                   num--;
               }
               mtx.unlock();
           }
     }
     stop = true;
     return args;
}

static void *work2(void* args){
    while(1){
        if(mtx.try_lock()){
            int len = s.size();
            if(stop && len % 4 == 0){
                mtx.unlock();
                return args;
            }
            if(len % 4 == 1){
                s += 'B';
            }
            mtx.unlock();
        }
    }
}

static void *work3(void* args){
    while(1){
        if(mtx.try_lock()){
            int len = s.size();
            if(stop && len % 4 == 0){
                mtx.unlock();
                return args;
            }
            if(len % 4 == 2){
                s += 'C';
            }
            mtx.unlock();
        }
    }
}

static void *work4(void* args){
    while(1){
        if(mtx.try_lock()){
            int len = s.size();
            if(stop && len % 4 == 0){
                mtx.unlock();
                return args;
            }
            if(len % 4 == 3){
                s += 'D';
            }
            mtx.unlock();
        }
    }
}

int main(){
    // cin>>num;
    // pthread_t tid1,tid2,tid3,tid4;
    // pthread_create(&tid1, NULL, work1, NULL);
    // pthread_create(&tid2, NULL, work2, NULL);
    // pthread_create(&tid3, NULL, work3, NULL);
    // pthread_create(&tid4, NULL, work4, NULL);
    // pthread_join(tid1,NULL);
    // pthread_join(tid2,NULL);
    // pthread_join(tid3,NULL);
    // pthread_join(tid4,NULL);
    // cout<<s<<endl;
    // stop = false;
    cout<<"A";
    char*str1= (char*)malloc(100);
    char*str2 = (char*)malloc(50);
    int *var = new int(5);
    //weixinchar *a = (char *)malloc(sizeof(char)*4);
    // _CrtDumpMemoryLeaks();
    return 0;
}