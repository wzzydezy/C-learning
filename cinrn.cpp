#include <iostream>
#include <vector>
#include <string.h>
#include <unordered_map>
#include <sstream>
#include <queue>
#include <stack>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>
#include <list>
#include <stdlib.h>
#include <cstdio>
using namespace std;

bool cmp(const pair<char,int> &a, const pair<char,int> &b){
    if(a.second==b.second) return a.first<b.first;
    else return a.second > b.second;
}
int main(){
    vector<string> nums;
    string s;
    while(getline(cin,s)){
        if(s.size()==0) break;
        nums.push_back(s);
    }
    unordered_map<char, int> map;
    for(int i=0;i<nums.size();i++){
        if(nums[i][4]>nums[i][6]){
            map[nums[i][0]] += 3;
            map[nums[i][2]];
        }
        else if(nums[i][4]<nums[i][6]){
            map[nums[i][2]] += 3;
            map[nums[i][0]];
        }
        else if(nums[i][4]==nums[i][6]){
            map[nums[i][0]] += 1;
            map[nums[i][2]] += 1;
        }
    }
    vector<pair<char,int>> res;
    unordered_map<char, int>::iterator i;
    for(i = map.begin();i !=map.end();i++){
        res.push_back(make_pair(i->first,i->second));
    }
    sort(res.begin(), res.end(), cmp);
    for(int i=0;i<res.size();i++){
        cout<<res[i].first<<" "<<res[i].second;
        if(i!=res.size()-1) cout<<",";
    }
    return 0;
}