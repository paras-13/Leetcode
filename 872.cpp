// 872. Leaf-Similar Trees
/*
* Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
* For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
* Two binary trees are considered leaf-similar if their leaf value sequence is the same.
* Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
*/
// Code -->
class Solution {
public:
    vector <int> v;
    void tree(TreeNode* root)
    {
        if(root == NULL) {
            return;
        } 
        tree(root->left);
        if(root->left == NULL && root->right == NULL) v.push_back(root->val);
        tree(root->right);

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        tree(root1);
        int ptr = v.size();
        tree(root2);
        int flag = 0;
        int i,j;
        for(i=0, j=ptr; i<ptr;i++, j++)
        {
            if(v[i] == v[j]) continue;
            else {flag = 1; break;}
        }
        if(flag) return false;
        else
        {
            if(j!=v.size()) return false;
            return true;
        }
        return true;
    }
};