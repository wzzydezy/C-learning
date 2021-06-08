#include <vector>
#include <string>
#include <iostream>
using namespace std;

string decode(string s){
    int x=-1,k=-1,y=-1;
    int i=0;
    while(i<s.size()){
        if(s[i]=='['){
            x = i;
        }
        if(s[i]=='|'){
            k = i;
        }
        if(s[i]==']'){
            y = i;
            break;
        }
        i++;
    }
    if(x!=-1 && k!=-1 && y!=-1){
        int n = 0;
        n = stoi(s.substr(x+1, k-x-1));
        string str = s.substr(k+1, y-k-1);
        string strs="";
        while(n--){
            strs.append(str);
        }
        //cout<<strs<<endl;
        s = s.substr(0,x) + strs + s.substr(y+1);
        //cout<<s<<endl;
        return decode(s);
    }
    return s;

}

int main(){
    string s;
    cin>>s;
    cout<<decode(s)<<endl;
    //cout<<s;
    return 0;
}