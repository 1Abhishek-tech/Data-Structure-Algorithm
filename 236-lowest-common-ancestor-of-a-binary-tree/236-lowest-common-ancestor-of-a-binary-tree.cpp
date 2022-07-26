#define vi vector<TreeNode*>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
//   bool findPath(TreeNode* root, int k , vi &path ){
//     if(root == NULL) return false;
//     path.push_back(root);
    
//     if(root->val == k) return true;
//     if(root->left) {
//       if(findPath(root->left , k , path)) return true;
//     }
//     if(root->right) {
//       if(findPath(root->right , k , path)) return true;
//     }
    
//     path.pop_back();
//     return false;
//   }
  
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          // Base case
    if (root == NULL) return NULL;
 
    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (root->val == p->val || root->val == q->val)
        return root;
 
    // Look for keys in left and right subtrees
    TreeNode *left_lca  = lowestCommonAncestor(root->left, p, q);
    TreeNode *right_lca = lowestCommonAncestor(root->right, p, q);
 
    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left_lca && right_lca)  return root;
 
    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL)? left_lca: right_lca;
//       vi path1, path2;
      
//       if(!findPath(root , p->val , path1) || !findPath(root , q->val , path2 ) )
//           return NULL;
//       for(int i = 0 ; i < path1.size() && i < path2.size() ; i++){
//         if(path1[i]->val != path2[i]->val) return path2[i-1];
//       }
//       return NULL;
    }
};