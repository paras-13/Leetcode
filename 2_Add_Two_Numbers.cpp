// 2. Add Two Numbers
// Leetcode Solution: 
/*
Ques:- You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* head = NULL;;
        int s1, s2, sum, carry=0;
        while(l1 || l2 || carry)
        {
            if(l1) s1 = l1->val;
            else s1=0;
            if(l2) s2=l2->val;
            else s2=0;
            sum = s1+s2+carry;
            carry = sum/10;

            ListNode* newnode = new ListNode(sum%10);
            newnode->next = NULL;
            if(head == NULL) head = newnode;
            else
            {
                ListNode* temp = head;
                while(temp->next) temp=temp->next;
                temp->next = newnode;
            }
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return head;
    }
};