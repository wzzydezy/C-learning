//Thread A -> func A -> while(1) printf(“A”) 
//Thread B -> func B -> while(1) printf(“B”) 
//Thread C -> func C -> while(1) printf(“C”) 
//控制输出：ABBCCCABBCCC…

#include <iostream>
#include <pthread.h>
#include <mutex>
#include <string>

using namespace std;

mutex mtx;
static int num = 0;
static void *funcA(void* arg){
    while(1){
        if(mtx.try_lock()){
            if(num % 6==0){
                cout<<"A";
                num++;
            }
            mtx.unlock();
        }
    }
    return arg;
}

static void *funcB(void* arg){
    while(1){
        if(mtx.try_lock()){
            if(num % 6==1 || num % 6==2){
                cout<<"B";
                num++;
            }
            mtx.unlock();
        }
    }
    return arg;
}

static void *funcC(void* arg){
    while(1){
        if(mtx.try_lock()){
            if(num % 6==3 || num % 6==4 || num % 6==5){
                cout<<"C";
                num++;
                if(num==6) num = 0;
            }
            mtx.unlock();
        }
    }
    return arg;
}

int main(){
    pthread_t tid1, tid2, tid3;
    pthread_create(&tid1, NULL, funcA, NULL);
    pthread_create(&tid2, NULL, funcB, NULL);
    pthread_create(&tid3, NULL, funcC, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    return 0;
}




