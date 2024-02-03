// 226. Diameter of a Binary Tree
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