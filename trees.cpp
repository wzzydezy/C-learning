#include <iostream>
#include <vector>
#include <string.h>
#include <unordered_map>
#include <sstream>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    static bool issametrees(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        return (root1->val==root2->val) && issametrees(root1->left, root2->right) 
        && issametrees(root1->right, root2->left);
    }

    void scan(TreeNode* root){
        if(!root) return;
        if(root->left) scan(root->left);
        if(root->right) scan(root->right);
        cout<<root->val<<" ";
        return;
    }
};

class scan2{
public:
    void midscan(TreeNode* root){
        stack<TreeNode*> sta;
        while(!sta.empty() || root){
            while(root){
                sta.push(root);
                root = root->left;
            }
            root = sta.top();
            cout<<root->val<<" ";
            sta.pop();
            root = root -> right;
        }
        return;
    }

    void prescan(TreeNode* root){
        stack<TreeNode*> sta;
        if(root) sta.push(root);
        while(!sta.empty()){
            TreeNode* root = sta.top();
            sta.pop();
            cout<<root->val<<" ";
            if(root->right) sta.push(root->right);
            if(root->left)  sta.push(root->left);
        }
        return;
    }

    void postscan(TreeNode* root){
        stack<TreeNode*> sta;
        if(root) sta.push(root);
        while(!sta.empty()){
            if(root->right) sta.push(root->right);
            if(root->left)  sta.push(root->left);
        }

    }

};

int maxpath(TreeNode* root, int& val){
    if(!root) return 0;
    int left = maxpath(root->left, val);
    int right = maxpath(root->right, val);
    int v = max(max(left,0), max(right,0)) + root->val;
    int mp = max(left,0) + max(right,0) + root->val;
    val = max(val, mp);
    return v; 
}
int maxPathSum(TreeNode* root) {
    int val = INT_MIN;
    maxpath(root, val);
    return val;
}

class Solution129 {
public:
    int res = 0;
    void dfs(TreeNode* root, int n){
        if(!root){
           res += n;
           return;
        }
        n = n*10 + root->val;
        if(root->left) dfs(root->left, n);
        if(root->right) dfs(root->right, n);
        return;
    }
    int sumNumbers(TreeNode* root) {
         dfs(root, 0);
         return res;
    }
};

int main(){
    Solution a;
    TreeNode* tn_0_0 = new TreeNode(1);
    TreeNode* tn_1_0 = new TreeNode(2);
    TreeNode* tn_1_1 = new TreeNode(3);
    //TreeNode* tn_2_0 = new TreeNode(2);
    //TreeNode* tn_2_1 = new TreeNode(3);
    TreeNode* tn_2_2 = new TreeNode(15);
    TreeNode* tn_2_3 = new TreeNode(7);
    tn_0_0->left = tn_1_0;
    tn_0_0->right = tn_1_1;
    //tn_1_0->left = tn_2_0;
    //tn_1_0->right = tn_2_1;
    //tn_1_1->left = tn_2_2;
    //tn_1_1->right = tn_2_3;
    //bool res = Solution::issametrees(tn_0_0, tn_0_0);
    //a.scan(tn_0_0);
    //int res = maxPathSum(tn_0_0);
    Solution129 s129;
    int res = s129.sumNumbers(tn_0_0);
    
    return 0;
}
