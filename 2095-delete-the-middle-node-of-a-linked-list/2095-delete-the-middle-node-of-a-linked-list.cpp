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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode harsh(0) ,*p=&harsh;
        vector<int>aksh;
        while (head != NULL)
            {
            aksh.push_back(head->val);
                head=head->next;
            }
        int n=aksh.size();
        
        for(int i=0;i<n;i++)
            {
            if(i==n/2)
                continue;
            else
            {
                
            
            p->next = new ListNode(aksh[i]);
            p=p->next;
            }
            }
        p->next=NULL;
        return harsh.next;
    }
};