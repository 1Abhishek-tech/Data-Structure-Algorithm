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
      
      ListNode* temp = head;
      int length = 1;
      while(temp->next != NULL){
        length++; temp = temp->next; 
      }
      temp->next = head;
      k = k%length;
      int steps = length - k;
      temp = head;
      for(int i = 1 ; i < steps ; i++){
        temp = temp->next;
      }
      head = temp->next;
      temp->next = NULL;
      return head;
      // 2 approaches discuss below 1 with On^2 and other using stack with On TC and On SC
      // ListNode* temp = head , *end;
      // int length = 1;
      // stack<ListNode*> st;
      // while(temp->next != NULL){
      //   length++; st.push(temp); temp = temp->next; 
      // }
      // k = k%length;
      // for(int i = 1 ; i <= k ; i++){
      //   // temp = head;
      //   // while(temp->next->next != NULL) temp = temp->next;
      //   temp = st.top(); st.pop();
      //   end = temp->next;
      //   temp->next = NULL;
      //   end->next = head;
      //   head = end;
      // }
      // return head;
    }
};