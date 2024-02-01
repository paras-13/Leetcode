// 543. Diameter of Binary Tree
/*
* Ques: Given the root of a binary tree, return the length of the diameter of the tree.
*       The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
*       The length of a path between two nodes is represented by the number of edges between them.
*/

// Code --> 
class Solution {
public:
    int findDia(TreeNode* root, int &dia)
    {
        if(root == NULL) return 0;
        int leftDia = findDia(root->left, dia);
        int rightDia = findDia(root->right, dia);
        dia = max(dia, leftDia+rightDia);
        return 1+max(leftDia, rightDia);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        findDia(root, dia);
        return dia;
    }
};