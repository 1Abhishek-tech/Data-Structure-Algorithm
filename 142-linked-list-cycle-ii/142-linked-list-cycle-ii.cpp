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
    ListNode *detectCycle(ListNode *head) {
      if(head == NULL || head->next == NULL) return nullptr;
//         unordered_set<ListNode*> mp;
//       ListNode* temp = head;

//       while(temp != nullptr){
//         if(mp.find(temp) != mp.end()){
//           return temp;
//         }
//         mp.insert(temp);
//         temp = temp->next;
//       }
//       return nullptr;
      ListNode* slow = head , *fast = head;
      while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next; fast = fast->next->next;
        if(slow == fast){
          ListNode* entry = head;
          while(slow != entry){
            slow = slow->next;
            entry = entry->next;
          }
          return slow;
        }
      }
      return nullptr;
    }
};