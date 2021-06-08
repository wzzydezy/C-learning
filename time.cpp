#include <iostream>
#include <vector>
#include <stack>
#include <time.h>
#include <sys/time.h>

using namespace std;

int main(){
    time_t t = time(NULL);
    struct tm *sys_tm = localtime(&t);
    struct tm my_tm = *sys_tm;
    //struct timespace z = {0,0};
    struct timeval now = {0,0};
    gettimeofday(&now, NULL);
    return 0;
}