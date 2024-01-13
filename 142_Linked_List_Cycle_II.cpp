// 142. Linked List Cycle II
/*
Ques --> Given the head of a linked list, return the node where the cycle begins.
If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be 
reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer 
is connected to (0-indexed). It is -1 if there is no cycle. 
Note that pos is not passed as a parameter.

Do not modify the linked list.
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;
        int flag=0;
        if(temp == NULL) return NULL;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow == fast) {flag=1;break;}
        }
        if(fast==NULL || fast->next==NULL) flag=0;
        if(flag)
        {
            while(temp!=slow)
            {
                temp=temp->next;
                slow=slow->next;
            }
            return temp;
        }
        else return NULL;
    }
};