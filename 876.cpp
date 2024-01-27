// 876. Middle of the Linked List
/*
* Ques:- Given the head of a singly linked list, return the middle node of the linked list.
*       If there are two middle nodes, return the second middle node.
*/
// Code-->
class Solution {
public:
    ListNode* middleNode(ListNode* head)
    {
        ListNode* fast=head;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};