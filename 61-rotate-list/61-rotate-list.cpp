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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;
      ListNode* temp = head , *end;
      int length = 1;
      while(temp->next != NULL){
        length++; temp = temp->next;
      }
      k = k%length;
      for(int i = 1 ; i <= k ; i++){
        temp = head;
        while(temp->next->next != NULL) temp = temp->next;
        end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
      }
      return head;
    }
};