// 257. Binary Tree Paths
/*
* Ques:
* Given the root of a binary tree, return all root-to-leaf paths in any order.
*   A leaf is a node with no children.
*/
// Code->
class Solution {
public:
    vector<string>v;
    void tracePath(TreeNode* root, string str)
    {
        if(root->left== NULL && root->right==NULL) {
            v.push_back(str+to_string(root->val));
        }
        if(root->left) {
            tracePath(root->left, str+to_string(root->val)+"->");
        }
        if(root->right) {
            tracePath(root->right,str+to_string(root->val)+"->");
        }
    }
    vector<string> binaryTreePaths(TreeNode* root)
    {
        string str="";
        if(root == NULL)
            return v;
        tracePath(root, str);
        return v;
    }
};