/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode* pre = NULL;
        DFS(root, pre, minDiff);
        return minDiff;
    }
    
    void DFS(TreeNode* root, TreeNode*& pre, int& minDiff){
        if(!root) return;
        DFS(root->left, pre, minDiff);
        if(pre) minDiff = min(minDiff, abs(root->val - pre->val));
        pre = root;
        DFS(root->right, pre, minDiff);
  }
};