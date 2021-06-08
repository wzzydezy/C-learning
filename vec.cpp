#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

class solution{
public:
    void rev(vector<int>& nums, int n){
        int i=0;
        n = (1<<n);
        int m = nums.size()/n;
        while(m--){
          reverse(nums.begin() + i , nums.begin()+i+n);
          i += n;
        }
    }
    
    int mergesort(vector<int>& nums, vector<int>& cop, int l, int r){
        if(l>=r) return 0;
        int mid = l + (r-l)/2;
        int count = mergesort(nums, cop, l, mid) + mergesort(nums, cop, mid+1, r);
        int i=l, pos=l, j=mid+1;
        while(i<=mid && j<=r){
            if(nums[i]<=nums[j]){
                cop[pos]=nums[i];
                count += j-mid-1;
                i++;
            }
            else{
                cop[pos]=nums[j];
                j++;
            }
            pos++;
        }
        for(int k=i;k<=mid;k++){
            cop[pos++]=nums[k];
            count += j-mid-1;
        }
        for(int k=j;k<=r;k++){
            cop[pos++]=nums[k];
        }
        copy(cop.begin()+l, cop.begin()+r+1, nums.begin()+l);
        return count;
    }
};

//leetcode300
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return 0;
    vector<int> dp(n,0);
    dp[0] = 1;
    int max = INT_MIN;
    for(int i=1;i<n;i++){
        if(nums[i]>nums[i-1] && nums[i]>=max){
            max= nums[i];
            dp[i]=dp[i-1]+1;
        }
        else{
            dp[i]=dp[i-1];
        }
    }
    return dp[n-1];
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n = nums1.size();
       int m = nums2.size();
       int l = n+m;
       int v1,v2;
       int i=0,j=0,k=0;
       while((i<n || j<m)){
           if(j>=m || (i<n && nums1[i]<=nums2[j])){
               if(k==l/2-1) v1 = nums1[i];
               else if(k==l/2) v2 = nums1[i];
               i++;
               k++;
           } 
           else{
               if(k==l/2-1) v1 = nums2[j];
               else if(k==l/2) v2 = nums2[j];
               j++;
               k++;
           }
       }
       return l%2==0 ? (v1+v2)/2.0 : v2;
}

//leetcode42
int trap(vector<int>& height) {
        int n = height.size();
        vector<int> right(n,0);
        vector<int> left(n,0);
        int maxright = 0;
        int maxleft = 0;
        for(int i=0;i<n;i++){
            maxright = max(maxright, height[i]);
            right[i] = maxright;
        }
        for(int i=n-1;i>=0;i--){
            maxleft = max(maxleft,height[i]);
            left[i] = maxleft;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += min(right[i],left[i])-height[i];
        }
        return ans;
}

int main(){
    // solution a;
    // int n;
    // cin>>n;
    // n = (1<<n);
    // vector<int> nums(n,0);
    // for(int i=0;i<n;i++){
    //     cin>>nums[i];
    // }
    // int m;
    // cin>>m;
    // vector<int> cur(m,0);
    // for(int i=0;i<m;i++){
    //     cin>>cur[i];
    // }
    // for(int i=0;i<m;i++){
    //     a.rev(nums, cur[i]);
    //     vector<int> cop(n,0);
    //     vector<int> nums2 = nums;
    //     int ans = a.mergesort(nums2, cop, 0, n-1);
    //     cout<<ans<<endl;
    // }
    // return 0;
    vector<int> nums1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    int res = trap(nums1);
    return 0;
}