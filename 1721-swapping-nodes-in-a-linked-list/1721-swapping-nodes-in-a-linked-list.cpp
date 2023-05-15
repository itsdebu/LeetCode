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
        if(!head or !head->next)return head;
        ListNode *a=head,*b=head,*temp=head;
        int count=0;
        int new_k=k;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        while(a)
        {
            if(k==1)break;
            a=a->next;
            k--;
        }
        int back=0;
        back=count-new_k;
        while(b)
        {
            if(back==0)break;
            b=b->next;
            back--;
        }
        swap(a->val,b->val);
        return head;
    }
};