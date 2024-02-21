// 572. SubTree of another tree
/*
* Ques:- Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
*/
class Solution
{
    public:
    bool isSameSubTree(TreeNode* root, TreeNode* subroot)
    {
        if(root==NULL && subroot == NULL) return true;
        if(root == NULL || subroot == NULL) return false;
        if(root->val != subroot->val) return false;
        return isSameSubTree(root->left, subroot->left) && isSameSubTree(root->right, subroot->right);
    }
    bool isSametree(TreeNode* root, TreeNode* subroot)
    {
        if(root == NULL && subroot == NULL) return true;
        bool check = isSameSubTree(root, subroot);
        if(check) return true;
        else
        {
            bool res = isSametree(root->left, subroot) || isSametree(root->right, subroot);
            return res;
        }
    }
};