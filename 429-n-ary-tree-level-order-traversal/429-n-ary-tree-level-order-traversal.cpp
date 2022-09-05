/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
  private:
  void bfs(Node* root , int level , vector<vector<int>> &res){
    if(root == NULL) return ;
    if(res.size() == level) res.push_back({});
    
    res[level].push_back(root->val);
    for(auto children : root->children){
      bfs(children , level+1 , res);
    }
  }
public:
    vector<vector<int>> levelOrder(Node* root) {
      vector<vector<int> > res;
      bfs(root , 0 , res);
      return res;
      //BFS Approach
//         vector<vector<int>> ans;
//       if(root == NULL) return ans;
//       queue<Node*> q; q.push(root);
      
//       while(!q.empty()){
//         int size = q.size();
//         vector<int> temp ;
//         while(size--){
//           Node* cur = q.front(); q.pop();
//           temp.push_back(cur->val);
//           for(auto nxt : cur->children){
//             if(nxt != NULL){
//               q.push(nxt);
//             }
//           }
          
//         }
//         ans.push_back(temp);
//       }
//       return ans;
    }
};