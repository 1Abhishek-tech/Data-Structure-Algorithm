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
  vector<vector<int>> ans;
  void help(TreeNode* root , int targetSum , int sum , vector<int> path){
    if(root->left == NULL && root->right == NULL){
    sum += root->val;
    path.push_back(root->val);      
      if(sum == targetSum)
        ans.push_back(path);
    sum -= root->val;
    path.pop_back();
    return; 
    }
    sum += root->val;
    path.push_back(root->val);
    // for(auto child : root){
    //   help(child , targetSum , sum , path);
    // }
    if(root->left) help(root->left , targetSum , sum , path);
    if(root->right) help(root->right , targetSum , sum , path);
    
    path.pop_back();
    sum -= root->val;
  }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
          return {};
      vector<int> path;
      help(root , targetSum , 0 , path);
      return ans;
    }
};