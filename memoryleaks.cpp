
#define CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#include <iostream>
//在入口函数中包含 _CrtDumpMemoryLeaks();  
//即可检测到内存泄露
 using namespace std;
//以如下测试函数为例：
int main()
{
	char* pChars = new char[10];
    cout<<"a";
	_CrtDumpMemoryLeaks();
	return 0;
}