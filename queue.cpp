#include <iostream>
#include <vector>
#include <string.h>
#include <unordered_map>
#include <sstream>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;

class Medianfinder{
public:
   priority_queue<int, vector<int>, less<int>> maxheap;
   priority_queue<int, vector<int>, greater<int>> minheap;
   Medianfinder(){

   }
   void addnum(int num){
       if(maxheap.size()==minheap.size()){
           maxheap.push(num);
           minheap.push(maxheap.top());
           maxheap.pop();
       }
       else{
           minheap.push(num);
           maxheap.push(minheap.top());
           minheap.pop();
       }
   }

   double findmedian(){
       int n = maxheap.top();
       int m = minheap.top();
       return maxheap.size()==minheap.size() ? (n+m)*0.5 :m;
   }
   

};

int main(){
    Medianfinder a;
    a.addnum(1);
    a.addnum(3);
    a.addnum(4);
    int mid = a.findmedian();
    cout << mid << endl;
    stack<int> sta;
    queue<int> que;
    priority_queue<int, vector<int>, less<int>> pque;
    deque<int> dque;
    sta.push(1);
    sta.push(2);
    que.push(1);
    que.push(2);
    pque.push(1);
    pque.push(2);
    dque.push_back(1);
    dque.push_back(2);
    dque.push_front(3);
    int res1 = sta.top();
    int res2 = que.front();
    int res3 = que.back();;
    int res4 = pque.top();
    int res5 = dque.front();
    int res6 = dque.back();
    return 0;
}