// 61. Rotate List Leetcode
/*
Ques:- Given the head of a linked list, rotate the list to the right by k places.
*/
// Code--> 
class Solution
{
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        ListNode* temp = head;
        ListNode* tail = NULL;
        int size=0;
        while(temp) {temp=temp->next; size++;}
        if(size<2 || head == NULL) return head;
        if(k > size) k=k%size;
        while(k)
        {
            temp = head;
            while(temp->next->next) temp=temp->next;
            tail = temp->next;
            temp->next = NULL;
            tail->next = head;
            head = tail;
            k--;
        }
        return head;
    }
};