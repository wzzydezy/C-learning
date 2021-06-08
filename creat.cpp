#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;//输入第一个数n，代表有n个数
    vector<int> nums(n,0);
    vector<int> res;
    int a = 0, b = 0;
    for(int i=0;i<n;i++){  //循环输入n次，获取这n个数
        cin>>nums[i];
        if(nums[i]==0) a++;
        else b++;
    }
    int c = 0;
    if(a>b)  c = 1;
    for(int i=0;i<n;i++){
        if(i<n-2 && nums[i]==c && (nums[i]==nums[i+1] || nums[i]==nums[i+2])){
            i = i+2;
        }
        else{
            res.push_back(nums[i]);
        }
    }
    int k0 = 0, k1 = 0;
    for(int i=0;i<res.size();i++){
        if(res[i]==1) k1++;
        else k0++;
    }
    int z = abs(k1-k0);
    cout<<z<<endl;
    return 0;
}

