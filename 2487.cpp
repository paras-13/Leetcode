// 2487. Remove Nodes From Linked List
/*
*Ques:
You are given the head of a linked list.
Remove every node which has a node with a greater value anywhere to the right side of it.
Return the head of the modified linked list.
*/
// Code:
class Solution
{
public:
    ListNode* removeNodes(ListNode* head)
    {
        if(!head || !head->next) return head;
        stack <ListNode*> st;
        ListNode* temp = head;
        while(temp)
        {
            while(!st.empty() && temp->val > st.top()->val)
                st.pop();
            st.push(temp);
            temp=temp->next;
        }

        ListNode* newhead = NULL;
        ListNode* t = NULL;
        while(!st.empty())
        {
            t = st.top();
            st.pop();
            t->next = newhead;
            newhead = t;
        }
        return newhead;

    }
};
