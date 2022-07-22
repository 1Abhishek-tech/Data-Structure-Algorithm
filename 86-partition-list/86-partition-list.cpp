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
      //vo sari nodes ki value jo x se choti hai vo choti list me ek k bad ek dalo(no sorting like arrangement) 
      if(head == NULL) return NULL;
      // ListNode* ptr1 = head , *currNode;
      ListNode* dummy11 = new ListNode() , *ptr11 = dummy11;
      ListNode* dummy12 = new ListNode() , *ptr12 = dummy12;
      
      while(head != NULL){
        if(head->val < x ){
          // currNode = new ListNode(ptr1->val);
          // ptr11->next = currNode;
          ptr11->next = head;
          ptr11 = ptr11->next , head = head->next;
        }
        else {
        // currNode = new ListNode(ptr1->val);
        // ptr12->next = currNode;
        ptr12->next = head;
        ptr12 = ptr12->next , head = head->next;
        }
      }
      ptr12->next = NULL;
      ptr11->next = dummy12->next;
      return dummy11->next;
      
    }
};