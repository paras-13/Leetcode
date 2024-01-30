// 102. Binary Tree Level Order Traversal
/*
* Ques:
*   Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
*/
// Code --> 
class Solution {
    public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>>vec;
        if(root == NULL) return vec;
        queue <TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(q.front()!=NULL)
        {
            vector<int>v;
            while(q.front()!=NULL)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                v.push_back(temp->val);
            }
            q.pop();
            q.push(NULL);
            vec.push_back(v);
        }
        return vec;
    }
}