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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* head = NULL , *nxt = NULL;
      int carry = 0;
      while(l1 || l2){
        int val1 = l1 ? l1->val : 0 ;
        int val2 = l2 ? l2->val : 0 ;
        int temp = val1 + val2 + carry;
        carry = temp/10;
        temp = temp%10;
        ListNode* curr = new ListNode(temp);
        if(!head) head = curr;
        if(nxt) nxt->next = curr;
        nxt = curr;
        l1 = l1? l1->next : NULL;
        l2 = l2? l2->next : NULL;
      }
      if(carry > 0){
        ListNode*  l = new ListNode(carry);
        nxt->next = l;
      }
      return head;
    }
};