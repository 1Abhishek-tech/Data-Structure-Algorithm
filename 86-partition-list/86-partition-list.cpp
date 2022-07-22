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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
      if(head == NULL) return NULL;
      ListNode* ptr1 = head , *currNode;
      ListNode* dummy11 = new ListNode() , *ptr11 = dummy11;
      ListNode* dummy12 = new ListNode() , *ptr12 = dummy12;
      
      while(ptr1 != NULL){
        if(ptr1->val < x ){
          currNode = new ListNode(ptr1->val);
          ptr11->next = currNode;
          ptr11 = ptr11->next , ptr1 = ptr1->next;
        }
        else {
        currNode = new ListNode(ptr1->val);
        ptr12->next = currNode;
        ptr12 = ptr12->next , ptr1 = ptr1->next;
        }
      }
      ptr11->next = dummy12->next;
      return dummy11->next;
      
    }
};