#include <iostream>
#include <vector>
#include <string.h>
#include<unordered_map>
#include<sstream>
#include<algorithm>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stringstream is(path);
        vector<string> strs;
        string res = "";
        string tmp = "";
        while(getline(is, tmp, '/')){
            if(tmp=="" || tmp=="."){
                continue;
            }
            else if(!strs.empty() && tmp==".."){
                strs.pop_back();
            }
            else if(tmp!=".."){
                strs.push_back(tmp);
            }
        }
        for(auto str:strs){
            res += '/' + str;
        }
        if(res=="") return "/";

        return res;
        
    }
};

int main(){
    vector<int> a ={1,2,3,4};
    reverse(a.begin(), a.end());
}