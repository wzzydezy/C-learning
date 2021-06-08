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
using namespace std;

class twofind{
public:
    //旋转数组查找最小一个数；
    int twofind_min(vector<int>& nums){
        int n = nums.size();
        int l=0,r=n-1;
        while(l<r){
            int mid = l + (r-l)>>1;
            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return nums[l];
    }
    //二分查找，找到第一个比目标值小的数
    int twofind_min(vector<int>& nums, int k){
        int n = nums.size();
        int l=0,r=n-1;
        int pos = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]<k){
                pos = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return nums[pos];
    }

};


int main(){
    vector<int> nums= {0,1,2,3,4,5,6,7};
    twofind a;
    int res = a.twofind_min(nums,5);
    int ans = res;
    return 0;
}