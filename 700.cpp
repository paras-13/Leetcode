// 700. Search in a Binary Search Tree
/*
* Ques: You are given the root of a binary search tree (BST) and an integer val.
*       Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.
*/
// Code -->
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val)
    {
        if(root == NULL) return root;
        queue <TreeNode*> q;
        int flag=0;
        TreeNode* temp = NULL;
        TreeNode* t = NULL;
        q.push(root);
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            if(temp->val == val) {flag = 1; break;}
            else
            {
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        if(flag) return temp;
        else return t;
    }
};