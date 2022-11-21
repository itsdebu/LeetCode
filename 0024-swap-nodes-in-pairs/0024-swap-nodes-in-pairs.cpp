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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp=head;
        while(temp and temp->next)
        {
            int val=temp->val;
            temp->val=temp->next->val;
            temp->next->val=val;
            temp=temp->next->next;
        }temp=head;
        return head;
    }
};