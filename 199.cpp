// 199. Binary Tree Right Side View
// Code -->
/*
* Ques: Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector <int> v;
        deque<TreeNode*>dq;
        if(root == NULL) return v;
        dq.push_back(root);
        while(!dq.empty())
        {
            int size = dq.size();
            v.push_back(dq.back()->val);
            for(int i=0; i<size;i++)
            {
                TreeNode* temp = dq.front();
                dq.pop_front();
                if(temp->left) dq.push_back(temp->left);
                if(temp->right) dq.push_back(temp->right);
            }
        }
        return v;
    }
};