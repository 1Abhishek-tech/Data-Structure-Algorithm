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
        unordered_set<ListNode*> mp;
      ListNode* temp = head;

      while(temp != nullptr){
        if(mp.find(temp) != mp.end()){
          return temp;
        }
        mp.insert(temp);
        temp = temp->next;
      }
      return nullptr;
    }
};