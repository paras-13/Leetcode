// 513. Find Bottom Left tree Value;
/*
* Ques:- Given the root of a binary tree, return the leftmost value in the last row of the tree.
*/
// Code -->
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue <TreeNode*> q;
        TreeNode* temp = NULL;
        q.push(root);
        while(!q.empty()) {
            temp = q.front();
            q.pop();
            if(temp->right) q.push(temp->right);
            if(temp->left) q.push(temp->left);
        }
        return temp->val;
    } 
};