/*
Given the head of a linked list, return the list after sorting it in ascending order
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105

Solution------------------
*/
class Solution {
public:
    ListNode* merge(ListNode *list1, ListNode *list2)
    {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode *h1=list1, *h2=list2;
        ListNode *prev, *nh;
        if(h1->val<=h2->val)
        {
            prev=h1;
            nh=prev;
            h1=h1->next;
        }
        else
        {
            prev=h2;
            nh=prev;
            h2=h2->next;
        }
        while(h1 && h2)
        {
            if(h1->val<=h2->val)
            {
                prev->next=h1;
                prev=h1;
                h1=h1->next;
            }
            else
            {
                prev->next=h2;
                prev=h2;
                h2=h2->next;
            }
          //  cout<<prev->val;
        }
        if(h1)
        {
            prev->next=h1;
        }
        else
        {
            prev->next=h2;
        }
        return nh;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *slow=head, *fast=head, *prev;
        while(fast && fast->next)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        ListNode *l1=sortList(head);
        ListNode *l2=sortList(slow);
        return merge(l1, l2);
        
    }
};
