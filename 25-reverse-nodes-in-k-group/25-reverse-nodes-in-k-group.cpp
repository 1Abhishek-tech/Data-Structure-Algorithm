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
  int lengthOfLinkedList(ListNode* head){
    int l = 0; 
    while(head != NULL){
      l++;
      head = head->next;
    }
    return l;
  }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
      
      int length = lengthOfLinkedList(head);
      ListNode* dummyHead = new ListNode(0);
      dummyHead->next = head;
      ListNode* pre = dummyHead;
      ListNode* curr ;
      ListNode* nex;
      
      while(length >= k){
        curr = pre->next;
        nex = curr->next;
        for(int i = 1 ; i < k ; i++){
          curr->next = nex->next;
          nex->next = pre->next;
          pre->next = nex;
          nex = curr->next;
        }
        pre = curr;
        length -= k;
      }
      return dummyHead->next;
    }
};