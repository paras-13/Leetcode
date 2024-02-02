// 938. Range Sum of BST
/*
* Ques:- Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].
*/
// Code-->
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        queue <TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp->val >=low && temp->val<=high) sum+= temp->val;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return sum;
    }
};