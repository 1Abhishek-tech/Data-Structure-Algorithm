/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
      
        node->val = node->next->val;
        node->next = node->next->next;
      
      // Naive Approach
      // ListNode * t = node;
      // while(t->next->next != NULL){
      //   t->val = t->next->val;
      //   t = t->next;
      // }
      // t->val = t->next->val;
      // t->next = NULL;
    }
};