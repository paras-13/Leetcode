// 1669. 1669. Merge In Between Linked Lists
/*
 * Ques:- You are given two linked lists: list1 and list2 of sizes n and m respectively.
 *        the ath node to the bth node, and put list2 in their place.
 * The blue edges and nodes in the following figure indicate the result:
*/

// Code->
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
    {
        int size=0;
        ListNode* temp = list1;
        ListNode* tail=NULL;
        while(temp) {temp=temp->next; size++;}
        temp = list2;
        while(temp->next) temp=temp->next;
        tail = temp;
        temp = list1;
        int ptr=0;
        while(temp)
        {
            if(a==0)
            {
            list1 = list2;
            list1->next = list2->next;
            }
            else if(ptr == a-1)
            {
                ListNode* local = temp->next;
                temp->next = list2;
                temp = local;
            }
            else if(ptr == b)
            {
                if(b==size-1) tail->next = NULL;
                else
                {
                    ListNode* t = temp->next;
                    temp->next = NULL;
                    tail->next = t;
                }

            }
            if(ptr == a-1) ptr++;
            else
            {
            ptr++;
            temp=temp->next;
            }
        }
        return list1;
    }
};