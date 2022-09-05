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
public:
  vector<int> v;
  void helperPostOrder(Node* root){
        if(root != NULL){
          for(auto children : root->children){
            helperPostOrder(children);
          }    
        v.push_back(root->val);
        }
  }
    vector<int> postorder(Node* root) {
      helperPostOrder(root);
      return v;
    }
};