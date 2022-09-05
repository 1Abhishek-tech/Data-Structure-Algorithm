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
  vector<int> v;
public:
    vector<int> postorderTraversal(TreeNode* root) {
      //   if(root != nullptr){
      //     postorderTraversal(root->left);
      //     postorderTraversal(root->right);
      //     v.push_back(root->val);
      //   }
      // return v;
      if(root == NULL) return v;
      stack<TreeNode*> st1; st1.push(root);
      stack<int> st2;
      
      while(!st1.empty()){
        TreeNode* curr = st1.top(); st1.pop();
        st2.push(curr->val);
        if(curr->left) st1.push(curr->left);
        if(curr->right) st1.push(curr->right);
      }
      
      while(!st2.empty()){
        v.push_back(st2.top()); st2.pop();
      }
      return v;
    }
};