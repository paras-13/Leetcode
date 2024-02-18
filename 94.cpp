// 94. Binary Tree Inorder Traversal
/*
* Ques: Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/
// Code -->
class Solution {
public:
    vector <int> v;
    void inorder(TreeNode* root)
    {
        if(root == NULL) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        if(root == NULL) return v;
        inorder(root);
        return v;
    }
};