/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode *f=headA, *s=headB;
        // if(headA->next==NULL||headB->next==NULL)
        // {
        //     return headA;
        // }
        int sizea=0,sizeb=0;
        while(f!=NULL)
        {
            sizea++;
            f=f->next;
        }
        while(s!=NULL)
        {
            sizeb++;
            s=s->next;
        }
       // cout<<sizea<<sizeb;
       f=headA;
       s=headB;
       if(sizea>sizeb)
       {
           int d = sizea-sizeb;
           while(d--)
           {
               f=f->next;
           }
       }
       if(sizea<sizeb)
       {
           int d = sizeb-sizea;
           while(d--)
           {
               s=s->next;
           }
       }
       while(f!=s)
       {
          // cout<<f->val<<" "<<s->val<<endl;
           f=f->next;
           s=s->next;
       }
        return f;
    }
};