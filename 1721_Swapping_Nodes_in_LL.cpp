/*
Linked List: 1721. Swapping Nodes In Linked List
Ques:- You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node
from the beginning and the kth node from the end (the list is 1-indexed).
*/
// Code--> 
class Solution
{
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* kthfront = NULL;
        ListNode* kthend = NULL;
        int size=0;
        while(temp)
        {
            size++;
            if(size == k) kthfront = temp;
            temp=temp->next;
        }
        temp = head;
        int pos = size-k+1;
        if(size<k || k==pos) return head;
         while (temp) {
            if (pos == 1) {
                kthend = temp;
                break;
            }
            temp = temp->next;
            pos--;
        }
        int swap = kthfront->val;
        kthfront->val = kthend->val;
        kthend->val = swap;
        return head;
    }
};