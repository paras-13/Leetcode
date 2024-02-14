// 897. Increasing Order Search Tree
/*
* Ques:- Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.
*/
// Code -->

class Solution {
public:
    queue <TreeNode* > q;

    void inorder(TreeNode* root) {
        if (root == NULL) return;
        inorder(root->left);
        q.push(root);
        inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL) return root;

        inorder(root);
        if(root!=NULL) root = q.front();
        TreeNode* temp = root;
        q.pop();

        while (!q.empty()) {
            temp->right = q.front();
            temp->left = NULL;
            temp = temp->right;
            q.pop();
        }
        temp->right = NULL;
        temp->left = NULL;
        return root;
    }
};