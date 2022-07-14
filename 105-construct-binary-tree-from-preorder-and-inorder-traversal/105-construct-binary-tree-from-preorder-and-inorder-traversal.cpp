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
  int pre = 0;
   TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int is,int ie,unordered_map<int,int> &mp) {
     if(is>ie) return nullptr;
     TreeNode* root = new TreeNode(preorder[pre++]);
     int index = mp[root->val];
     // for(int i=is;i<=ie;i++)
     //   if(inorder[i] == root->val){
     //     index = i;
     //     break;
     //   }
     
     root->left = helper(preorder,inorder,is,index-1,mp);
     root->right = helper(preorder,inorder,index+1,ie,mp);
     return root;
   }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i; 
        }
      return helper(preorder,inorder,0,n-1,mp);
    }
};