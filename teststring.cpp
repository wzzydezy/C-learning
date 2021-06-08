#include <iostream>
#include <vector>
#include <string.h>
#include<unordered_map>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;


int main(){
    char *m_url;
    char *m_version;
    char *m_host;
    char *m_method;
    string s = "GET http://192.168.199.111:9008/ HTTP/1.1";
    char* text = &s[0];
    m_url = strpbrk(text, " \t");
    if(!m_url)
    {
        cout << "NO m_url" <<endl;
    }
    *m_url++ = '\0';
    char *method = text;
    if(strcasecmp(method, "GET") == 0)
        cout<< "GET" <<endl;
    else if(strcasecmp(method, "POST") == 0)
    {
        cout<< "POST" <<endl;
    }
    else 
        cout << "fasle" <<endl;
    
    cout<< m_url<< endl;
    m_url += strspn(text, " \t");
    cout<< m_url<< endl;
    m_version = strpbrk(m_url, " \t");
    cout<< m_version << endl;
    if(!m_version)
       cout<< "BAD_REQUEST"<<endl;
    *m_version++ = '\0';
    cout<< m_version << endl;
    m_version += strspn(m_version, " \t");
    cout<< m_version << endl;
    if(strcasecmp(m_version, "HTTP/1.1") != 0)
       cout<< "BAD_REQUEST"<<endl;

    if(strncasecmp(m_url, "http://", 7) == 0)
    {
        m_url += 7;
        m_url = strchr(m_url, '/');
    }
    if(strncasecmp(m_url, "https://", 8) == 0)
    {
        m_url += 8;
        m_url = strchr(m_url, '/');
    }
    if(!m_url || m_url[0] != '/')
        cout<< "BAD_REQUEST" <<endl;
    if(strlen(m_url) == 1)
        strcat(m_url, "judge.html");
    
    //cout << text << endl;
    return 0;
}