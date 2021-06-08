#include <iostream>
#include <vector>
#include <string.h>
#include<unordered_map>
#include <algorithm>
using namespace std;


class Solution{
public:
    void choosesort(vector<int>& nums){
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[i]){
                    swap(nums[i], nums[j]);
                }
            }
        }
        return;
    }

    void maopaosort(vector<int>& nums){
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=1;j<n-i;j++){
                if(nums[j]<nums[j-1]){
                    swap(nums[j-1], nums[j]);
                }
            }
        }
        return;
    }

    void insertsort(vector<int>& nums){
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i; j>=1 && nums[j]<nums[j-1];j--){
                swap(nums[j], nums[j-1]);
            }
        }
        return;
    }

    void shellsort(vector<int>& nums){
        int n = nums.size();
        for(int gap = n/2;gap>0;gap=gap/2){
            for(int i = gap; i<n;i++){
                for(int j=i; j-gap>=0 && nums[j]<nums[j-gap];j = j-gap){
                    swap(nums[j], nums[j-gap]);
                }
            }
        }
    }

    void mergesort(vector<int>& nums, vector<int>& cur, int l, int r){
        if(l>=r) return;
        int mid =  l + (r-l)/2;
        mergesort(nums, cur, l, mid);
        mergesort(nums, cur, mid+1, r);
        int i = l, j = mid+1, pos = l;
        while(i<=mid && j<=r){
            if(nums[i]<=nums[j]){
                cur[pos] = nums[i];
                i++;
            }
            else{
                cur[pos] = nums[j];
                j++;
            }
            pos++;
        }
        for(int k=i; k<=mid; k++){
            cur[pos++] = nums[k];
        }
        for(int k=j; k<=r; k++){
            cur[pos++] = nums[k];
        }
        copy(cur.begin()+l, cur.begin()+r+1, nums.begin()+l);
        return;
    }

    int randomize_partition(vector<int>& nums, int l, int r){
        int i = rand() % (r-l+1) + l;
        swap(nums[i], nums[r]);
        return partition(nums, l, r);
    }

    int partition(vector<int>& nums, int l, int r){
        int midvalue = nums[r];
        int i = l - 1;
        for(int j=l;j<r;j++){
            if(nums[j]<midvalue){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[r]);
        return i+1;
    }

    void quicksort(vector<int>& nums, int l, int r){
        if(l>=r) return;
        int pos = randomize_partition(nums, l ,r);
        quicksort(nums, l, pos-1);
        quicksort(nums, pos+1, r);
        return;
    }

};

//vector<int> nums = {5,34,43,6,2,4,5,6,7};

int main()
{ 
   vector<int> nums = {5,0,9,6,2,4,1,6,7};
   //sort(nums.begin(), nums.end());
   int n = nums.size();
   vector<int> cur(n, 0);
   Solution a;
   a.shellsort(nums);
   //a.mergesort(nums, cur, 0, n-1);
   //a.quicksort(nums, 0, n-1);
   //cout << boolalpha << ans << endl;
   return 0;

}