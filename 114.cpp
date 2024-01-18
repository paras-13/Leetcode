// 114. Flatten Binary Tree to Linked List
/*
Ques:- Given the root of a binary tree, flatten the tree into a "linked list":

    The "linked list" should use the same TreeNode class where the right child pointer
    points to the next node in the list and the left child pointer is always null.
    The "linked list" should be in the same order as a pre-order traversal of the binary tree.
*/
// Code -->
class Solution
{
public:
    void flatten(TreeNode* root)
    {
        TreeNode* last = NULL;
        preorder(root, last);
    }

    void preorder(TreeNode* root, TreeNode* &last)
    {
        if(root == NULL) return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if(last == NULL) last = root;
        else
        {
            last->left=NULL;
            last->right=root;
            last = root;
        }
        preorder(left, last);
        preorder(right, last);
    }
};