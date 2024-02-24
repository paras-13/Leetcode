// 637. Average of Levels In Binary Tree;
/*
* Qs:- Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted. 
*/
// Code --> 
class Solution {
public:
vector <double> v;
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == NULL) return v;
        queue <TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(q.front()!=NULL) {
            double sum = 0;
            int size = q.size()-1;
            while(q.front()!=NULL) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            q.pop();
            q.push(NULL);
            v.push_back(sum/size);
        }
        return v;
    }
};