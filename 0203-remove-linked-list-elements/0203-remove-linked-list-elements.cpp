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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
 ListNode* temp = head;
 vector<int> v;
 while(temp!=NULL){
     if(temp->val==val){
         v.push_back(temp->val);
         v.pop_back();
         temp = temp->next;
     }else{
         v.push_back(temp->val);
         temp = temp->next;
     }
         
 }
 ListNode *ans = new ListNode(-1);
 ListNode *cute = ans;
for(int i=0;i<v.size();i++){
    ListNode *j = new ListNode(v[i]);
    ans->next = j;
    ans = ans->next;
}
 return cute->next;
    }
};