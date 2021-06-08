#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool judge(string s){
    int  n = s.size();
    int m = n/2;
    int i=0;
    while(i<=m){
        if(s[i]!=s[n-1]){
            return false;
        }
        i++;
        n--;
    }
    return true;
}

int main(){
    bool res = judge("");
    return 0;
}