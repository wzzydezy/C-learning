#include<stdio.h>
#include<iostream>
using namespace std;

template <typename T>
class Shared_ptr{
private:
  size_t* m_count;
  T* m_ptr;

public:
  //构造函数
  Shared_ptr():m_ptr(nullptr), m_count(new size_t){}
  Shared_ptr(T* ptr):m_ptr(ptr), m_count(new size_t){
      cout<<"空间申请:"<<ptr<<endl;
      *m_count = 1;
  }
  ~Shared_ptr(){
      --(*m_count);
      if(*m_count==0){
          cout<<"空间释放："<<m_ptr<<endl;
          delete m_ptr;
          delete m_count;
          m_ptr = nullptr;//delete之后要将指针悬空
          m_count = nullptr;
      }
  }
  //拷贝构造函数
  Shared_ptr(const Shared_ptr& ptr){
      //cout<<"拷贝构造:"<<endl;
      m_count = ptr.m_count;
      m_ptr = ptr.m_ptr;
      ++(*m_count);
  }

  void operator= (const Shared_ptr& ptr){
      Shared_ptr(move(ptr));
  }

  T& operator*(){
      return *m_ptr;
  }

  T* operator->(){
      return m_ptr;
  }
};

template<typename T>
class SharePtr
{
public:
    SharePtr():_ptr(nullptr),_pcount(new int(1)){}; //默认构造函数
    SharePtr(T *ptr):_ptr(ptr), _pcount(new int(1)){};//初始化构造函数
    SharePtr(const SharePtr& s):_ptr(s.ptr), _pcount(s._pcount){
        *(_pcount)++;
    }
    SharePtr<T>& operator=(const SharePtr& s){
        if(this != s){
            if(--(*(this->_pcount))==0)
            {
                delete this->_ptr;
                delete this->_pcount;
            }
            this->_ptr = s._ptr;
            this->_pcount = s._pcount;
            (*(this->_pcount))++;
        }
        return *this;
    }

    T& operator*()
    {
        return *(this->_ptr);
    }
    T* operator->()
    {
        return this->_ptr;
    }

    ~SharePtr()
    {
        --(*(this->_pcount));
        if(this->_pcount==0)
        {
            delete _ptr;
            _ptr = nullptr;
            delete _pcount;
            _pcount = nullptr;
        }
    }
    
private:
    T* _ptr;
    size_t *_pcount;

};

int main(){
    Shared_ptr<int> p1(new int);
    Shared_ptr<int> p2 = p1;
    return 0;
}



