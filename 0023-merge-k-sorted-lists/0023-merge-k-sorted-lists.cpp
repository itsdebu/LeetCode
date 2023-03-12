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
    ListNode* mergeKLists(vector<ListNode*>& list) {
        if(list.empty())return NULL;
        vector<int>v;
        for(int i=0;i<list.size();i++)
        {
            ListNode* temp=list[i];
            while(temp!=NULL)
            {
                v.push_back(temp->val);
                temp=temp->next;
            }
        }sort(v.begin(),v.end());
        ListNode* head = new ListNode(0), *curr = head;
        int i = 0;
        while(i < v.size()){
            curr->next = new ListNode(v[i++]);
            curr = curr->next;
        }
        
        return head->next;
    }
};