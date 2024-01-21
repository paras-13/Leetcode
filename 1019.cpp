// 1019. Next Greater Node In Linked List
/*
* Ques:- You are given the head of a linked list with n nodes.
*       For each node in the list, find the value of the next greater node.
*       That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

*       Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed).
*       If the ith node does not have a next greater node, set answer[i] = 0.
*/

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head)
    {
        vector <int> v;
        ListNode* temp = head;
        while(temp)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        stack <int> st;
        st.push(0);
        for(int i=v.size()-1; i>=0; i--)
        {
            int val = v[i];
            while(st.top()!=0 && val>=st.top())
                st.pop();
            v[i] = st.top();
            st.push(val);
        }
        // int x=0;
        // int flag=0;
        // for(int i=0; i<v.size(); i++)
        // {
        //     if(i==v.size() - 1) {v[i] = 0; break;}
        //     for(int j=i+1; j<v.size(); j++)
        //     {
        //         if(v[j]>v[i]) 
        //         {
        //             flag=1;
        //             x = v[j];
        //             v[i]=x;
        //             break;
        //         }
        //         else flag=0;
        //     }
        //     if(flag==0)
        //     {
        //         v[i] = 0;
        //         flag=0;
        //     }
        // }
        return v;
    }
};