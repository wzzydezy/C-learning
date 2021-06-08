#include <vector>
#include <iostream>
using namespace std;

class solution{
int ans = 0;
public:
    int find(int a, int b, int c, int n){
        vector<vector<int>> nums(n+2, vector<int>(5,0));
        backtrace(nums, 1, 1, a, b, c);
        return ans;
    }
    
    void backtrace(vector<vector<int>>& nums, int i, int j, int a, int b, int c){
        if(a<0 || b<0 || c<0){
            return;
        }
        if(a==0 && b==0 && c==0){
            ans++;
            cout<<nums[1][1]<<nums[1][2]<<nums[1][3]<<endl;
            cout<<nums[2][1]<<nums[2][2]<<nums[2][3]<<endl;
            return;
        }
        if(j>nums[0].size()-2){
            j=1;
            i++;
        }
        if(i>nums.size()-2){
            return;
        }

        for(int k=1;k<=3;k++){
            if(k==1 && a==0) continue;
            if(k==2 && b==0) continue;
            if(k==3 && c==0) continue;
            if(nums[i-1][j]!=k && nums[i+1][j]!=k && nums[i][j-1]!=k && nums[i][j+1]!=k){
                nums[i][j]=k;
                if(k==1) a--;
                if(k==2) b--;
                if(k==3) c--;
                backtrace(nums, i, j+1, a, b, c);
                nums[i][j] = 0;
                if(k==1) a++;
                if(k==2) b++;
                if(k==3) c++;
            }
        }
        return;
    }
};



int main(){
    solution s;
    int a,b,c;
    cin>>a>>b>>c;
    int n;
    cin>>n;
    int res = s.find(a, b, c, n);
    cout<<res;
}