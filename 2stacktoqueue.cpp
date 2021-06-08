#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class Myqueue{
public:
       Myqueue();
       ~Myqueue();
       void pop();
       T front();
       void push(T n);
private:
    stack<T> s1;
    stack<T> s2;
};

template< typename T >
Myqueue< T > ::Myqueue(){
    //stack<T> s1;
    //stack<T> s2;
}

template< typename T>
Myqueue< T > ::~Myqueue(){

}

template< typename T >
void Myqueue<T> ::push(T n){
     s1.push(n); 
}

template< typename T>
T Myqueue<T> ::front(){
         if(s1.empty() && s2.empty()){
              cout<<"front error : No thing"<<endl;
          }
          else if(!s1.empty() && s2.empty()){
              while(!s1.empty()){
                  T cur = s1.top();
                  s2.push(cur);
                  s1.pop();
              }
          }
          return s2.top();
}

template< typename T>
void Myqueue<T>::pop(){
          if(s1.empty() && s2.empty()){
              cout<<"pop error : No thing"<<endl;
          }
          else if(!s1.empty() && s2.empty()){
              while(!s1.empty()){
                  T cur = s1.top();
                  s2.push(cur);
                  s1.pop();
              }
              s2.pop();
          }
          else{
              s2.pop();
          }
          return;
}



int main(){
    Myqueue<int> que;
    que.push(1);
    que.push(2);
    int n1 = que.front();
    que.push(3);
    que.pop();
    int n2 = que.front();
    que.pop();
    return 0;
}