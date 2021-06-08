#include <iostream>
#include <vector>
#include <string.h>
#include<unordered_map>
#include<sstream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
      
};

class Solution{
public:
    ListNode* firstnode(ListNode *headA, ListNode *headB){
        ListNode* node1 = headA;
        ListNode* node2 = headB;
        while(node1!=node2){
            node1 = node1!=nullptr ? node1->next : headB;
            node2 = node2!=nullptr ? node2->next : headA;
        }
        return node1;
    }

    ListNode* reverselist1(ListNode *head){
        if(!head) return nullptr;
        if(!head->next) return head;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur){
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    ListNode* reverselist2(ListNode *head){
         if(!head || !head->next) return head;
         ListNode* newnode = reverselist2(head->next);
         head->next->next = head;
         head->next = nullptr;
         return newnode;
    }
};

class mylist{
public:
    static ListNode* buildlist(vector<int>& nums){
        int n = nums.size();
        vector<ListNode*> numnode;
        ListNode* tmp = nullptr;
        for(int i=0;i<n;i++){
           numnode.push_back(new ListNode(nums[i]));
           if(tmp!=nullptr){
               tmp->next = numnode[i];
           }
           tmp = numnode[i];
        }
        return numnode[0];
    }
};

int main()
{/* int n1 = 8;
   int n2 = 3;
   vector<ListNode*> numnode1;
   vector<ListNode*> numnode2;
   while(n1--){
       numnode1.push_back(new ListNode(n1));
   }
   for(int i=0;i<numnode1.size()-1;i++){
      numnode1[i]->next = numnode1[i+1];
   }
   while(n2--){
       numnode2.push_back(new ListNode(n2));
   }
   for(int i=0;i<numnode2.size();i++){
       if(i!=numnode2.size()-1){
           numnode2[i]->next = numnode2[i+1];
       }
       else{
           numnode2[i]->next = numnode1[i+1];
       }
   }*/
   vector<int> nums1 = {1,2,3,4,5,6,7,8};
   vector<int> nums2 = {9,10,11,12};
   //mylist myln;
   ListNode* node1 = mylist::buildlist(nums1);
   ListNode* node2 = mylist::buildlist(nums2);
   node2->next->next->next = node1->next->next->next;
   Solution a;
   //ListNode* res = a.firstnode(node1, node2);
   ListNode* res = a.reverselist2(node1);
   return 0;
}