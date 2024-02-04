#include <bits/stdc++.h>
// 103. Binary Tree Zigzag Level Order Traversal
/*
* Ques:- Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
*/
// Code -->
class Solution
{
    public:
    vector<vector<int>>zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> vec;
        if(root == NULL) return vec;
        stack<TreeNode*>st1, st2;    // ? Using two stacks
        st1.push(root);
        while(!st1.empty() || !st2.empty())
        {
            vector <int> v;
            while(!st1.empty())
            {
                TreeNode* temp = st1.top();
                st1.pop();
                v.push_back(temp->val);
                if(temp->left) st2.push(temp->left);
                if(temp->right) st2.push(temp->right);
            }
            if(!v.empty()) vec.push_back(v);
            v.clear();
            while(!st2.empty())
            {
                TreeNode* temp = st2.top();
                st2.pop();
                v.push_back(temp->val);
                if(temp->right) st1.push(temp->right);
                if(temp->left) st1.push(temp->left);
            }
            if(!v.empty()) vec.push_back(v);
        }
        return vec;
    }
};