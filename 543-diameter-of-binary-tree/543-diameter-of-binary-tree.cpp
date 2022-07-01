/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int diameterOfBinaryTree(TreeNode *root)
        {
            int dia = INT_MIN;
            getDepth(root, dia);
            return dia;
        }

    int getDepth(TreeNode *p, int &dia)
    {
        if (p != NULL)
        {
            int l = getDepth(p->left, dia);
            int r = getDepth(p->right, dia);
            if (l + r > dia)
            {
                dia = l + r;
            }
            return max(l, r) + 1;
        }
        return 0;
    }
};