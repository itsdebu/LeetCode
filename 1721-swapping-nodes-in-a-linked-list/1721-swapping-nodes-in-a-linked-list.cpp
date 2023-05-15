/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int>v;
        while(head)
        {
            v.push_back(head->val);
            head=head->next;
        }
        swap(v[k-1],v[v.size()-k]);
        ListNode *vL =new ListNode(v[0]);
        ListNode * copy=vL;
        for(int i=1;i<v.size();i++)
        {
            ListNode *a=new ListNode(v[i]);
            copy->next=a;
            copy=copy->next;
        }
        return(vL);
    }
};