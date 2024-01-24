// 2130. Maximum Twin Sum of a Linked List
/*
* Ques:- In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.
    *   For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.

*   The twin sum is defined as the sum of a node and its twin.
*   Given the head of a linked list with even length, return the maximum twin sum of the linked list.
*/
// Code
class Solution {
public:
    int pairSum(ListNode* head)
    {
        // ? Approach 1
        // vector <int> v;
        // ListNode* temp = head;
        // while(temp)
        // {
        //     v.push_back(temp->val);
        //     temp=temp->next;
        // }
        // int ptr1=0, ptr2=v.size()-1;
        // int m=0, cond=v.size()/2;
        // while(cond)
        // {
        //     m = max(m, v[ptr1]+v[ptr2]);
        //     cond--;
        //     ptr1++; ptr2--;
        // }
        // return m;

        // ? Approach 2
        stack<int> st;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        while(slow)
        {
            st.push(slow->val);
            slow=slow->next;
        }
        fast=head;
        int m=0;
        while(!st.empty())
        {
            m = max(m, fast->val+st.top());
            st.pop(); fast=fast->next;
        }
        return m;
    }
};