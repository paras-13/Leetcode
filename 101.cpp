// 101. Symmetric Tree
/*
* Ques:- Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/ 
// Code --> 
class Solution
{
    public:
    bool isSymmetric(TreeNode* root)
    {
        if(root == NULL) return true;
        queue <TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty())
        {
            TreeNode* leftNode = q.front();
            q.pop();
            TreeNode* rightNode = q.front();
            q.pop();
            if(leftNode == NULL && rightNode == NULL) continue;
            if(leftNode == NULL || rightNode == NULL || leftNode->val!=rightNode->val) return false;
            q.push(leftNode->left);
            q.push(rightNode->right);
            q.push(leftNode->right);
            q.push(rightNode->left);
        }
        return true;
    }
};