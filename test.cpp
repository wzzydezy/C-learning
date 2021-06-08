#include <iostream>
#include <vector>
#include <string.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;


class Solution{
public:
    bool compare(string& s){
       unordered_set<int> set;
       unordered_map<char, int> map;
       int n = s.size();
       for(int i=0;i<n;i++){
           map[s[i]]++;
       }
       int res = 0;
       for(auto& m:map){
          res += (m.second%2);
       }
       return res<=1;

    }
};

string s = "abbacc";

int main()
{ 
   string a = "abcde";
   string b = a;
   a[2] = 'a';
   cout<<a<<endl;
   cout<<b<<endl;
   return 0;

}

// int judge(int n)
// {
//     if(n%3==0){
//         return n/3;
//     }
//     else if(n%2==0){
//         return n/2;
//     }
//     else return n-1;
// }

// int judge2(int n)
// {
//     if((n-1)%3==0){
//         return (n-1)/3;
//     }
//     else if((n-1)%2==0){
//         return (n-1)/2;
//     }
//     else return n-1;
// }

// int main(){
//     int n;
//     cin>>n;
//     vector<int> nums(n);
//     for(int i=0;i<n;i++){
//         cin>>nums[i];
//     }
//     for(int i=0;i<n;i++){
//         int ans = nums[i];
//         vector<int> nums;
//         while(ans!=0){
//             if(!nums.size()){
//                 nums.push_back(ans);
//             }
//             else if(nums.size()==1)
//             {
//                 ans = judge(nums[nums.size()-1]);
//                 nums.push_back(ans);
//             }
//             else
//             {
//                 ans = min(judge(nums[nums.size()-1]), judge2(nums[nums.size()-2]));
//                 nums.push_back(ans);
//             }
//         }
//         cout << int(nums.size() - 1) <<endl;

//     }
//     return 0;
// }