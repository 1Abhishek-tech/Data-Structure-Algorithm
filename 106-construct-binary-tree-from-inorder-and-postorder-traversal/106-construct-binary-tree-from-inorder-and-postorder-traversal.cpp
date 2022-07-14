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
  int post;
  TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int is,int ie,unordered_map<int,int> &mp) {
    if(is>ie) return nullptr;
    TreeNode* root = new TreeNode(postorder[post--]);
    int index = mp[root->val];
    
    root->right = helper(inorder,postorder,index+1,ie,mp);
    root->left = helper(inorder,postorder,is,index-1,mp);
    return root;
  }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
      post = n-1;
      unordered_map<int,int> mp;
      for(int i=0;i<n;i++){
        mp[inorder[i]] = i;
      }
      return helper(inorder,postorder,0,n-1,mp);
    }
};