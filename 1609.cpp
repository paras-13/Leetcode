// 1609. Even Odd Tree
/*
* Ques:- 
*A binary tree is named Even-Odd if it meets the following conditions:

*    The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
*    For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
*    For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).

*   Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.
*/
// Code -->
class Solution {
public:
    bool isEvenOddTree(TreeNode* root)
    {
        queue <TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int level = 0;
        while(q.front()!=NULL)
        {
            int evenorder = 0, oddorder=INT_MAX;
            while(q.front()!=NULL)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(level%2==0)
                {
                    if(temp->val%2 != 0 && temp->val > evenorder) evenorder = temp->val;
                    else return false;
                }
                else
                {
                    if(temp->val%2==0 && temp->val < oddorder) oddorder = temp->val;
                    else return false;
                }
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            q.pop();
            q.push(NULL);
            level++;
        }
        return true;
    }
};