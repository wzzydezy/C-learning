

#include <iostream>
#include <string>

using namespace std;

class A
{
public:
    A(){
        cout<<"A"<<endl;
    }
    ~A(){
        cout<<"~A"<<endl;
    }
    void fun1(string a){
        cout<<a<<endl;
        return;
    }
};

class B:  public A
{
public:
    B(){
        cout<<"B"<<endl;
    }
    ~B(){
        cout<<"~B"<<endl;
    }
};

class C:  public A
{
public:
    C(){
        cout<<"C"<<endl;
    }
    ~C(){
        cout<<"~C"<<endl;
    }
};

class D:public B, public C
{
public:
    D(){
        cout<<"D"<<endl;
    }
    ~D(){
        cout<<"~D"<<endl;
    }
};

class F{
    char a;
    double b;
    int c;
};

class E:public F{
    int d;
};

int main(){
    E e;
    cout<<sizeof(e)<<endl;
    return 0;
}