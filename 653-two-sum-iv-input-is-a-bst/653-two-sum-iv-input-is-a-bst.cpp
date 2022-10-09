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
  void inorder(TreeNode* root, vector<int>& elem){
    if(root == NULL ) return ;
    
    inorder(root->left, elem);
    elem.push_back(root->val);
    inorder(root->right, elem);
  }
  
    bool findTarget(TreeNode* root, int k) {
      if(root->left == NULL && root->right == NULL) return false;
        vector<int> elem;
      inorder(root,elem);
      int n = elem.size();
      int i = 0 , j = n-1;
      while(i < j){
        int sum = elem[i] + elem[j];
        if(sum == k ) return true;
        else if (sum > k) j--;
        else i++;
      }
      return false;
    }
};