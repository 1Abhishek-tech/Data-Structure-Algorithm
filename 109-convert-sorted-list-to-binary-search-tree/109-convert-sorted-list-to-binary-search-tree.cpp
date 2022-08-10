/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
  // int middle(int mid ,ListNode* head  ){
  //   if(mid == 0) return head->val;
  //   ListNode* temp = new ListNode();
  //   temp = head;
  //   while(mid--){
  //     if(temp->next)
  //     temp = temp->next;
  //   }
  //   return temp->val;
  // }
    TreeNode* helper(vector<int> &nums , int l , int r){
      if(l>r) return nullptr;
      int mid = (l+r)/2;
      // int data = middle(mid,head);
      TreeNode* root = new TreeNode(nums[mid]);
      root->left = helper(nums, l , mid - 1);
      root->right = helper(nums , mid + 1 , r);
      return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
      if(head == nullptr) return nullptr;
      // int len = 1;
      // while(head->next){
      //   len++; head = head->next;
      // }
      vector<int> nums;
      while(head->next){
        nums.push_back(head->val);
        head = head->next;
      }
      nums.push_back(head->val);
        return helper(nums,0 , nums.size()-1);
    }
};