// 1290. Convert Binary Number in a Linked List to Integer
/*
Ques: Given head which is a reference node to a singly-linked list.
The value of each node in the linked list is either 0 or 1. 
The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.
*/
// Code--> 
class Solution
{
public:
    int getDecimalValue(ListNode* head)
    {
        string bin;
        int sum=0;
        int ptr=0;
        if (head == NULL) return 0;
        while(head)
        {
            bin.push_back((char)head->val);
            head = head->next;
        }
        for(int i=bin.length()-1; i>=0; i--)
        {
            int temp = (int)bin[i];
            if(temp == 1) sum += pow(2, ptr);
            ptr++;
        }
        return sum;
    }
};