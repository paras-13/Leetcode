// 100. Same Tree
/*
* Ques:-
*   Given the roots of two binary trees p and q, write a function to check if they are the same or not.
*   Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
*/
// Code -->
class Solution {
    public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        queue <TreeNode*> Q;
        Q.push(p);
        Q.push(q);
        while(!Q.empty())
        {
            TreeNode* t1 = Q.front();
            Q.pop();
            TreeNode* t2 = Q.front();
            Q.pop();
            if(t1 == NULL && t2 == NULL) continue;
            if(t1==NULL || t2 == NULL || t1->val!=t2->val) return false;
            Q.push(t1->left);
            Q.push(t2->left);
            Q.push(t1->right);
            Q.push(t2->right);
        }
        return true;
    }
};
