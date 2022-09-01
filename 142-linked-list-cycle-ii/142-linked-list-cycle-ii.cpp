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
        unordered_map<ListNode*, int > mp;
      ListNode* temp = head;
      int i = 0;
      while(temp != nullptr){
        if(mp.find(temp) != mp.end()){
          return temp;
        }
        mp[temp] = i++;
        temp = temp->next;
      }
      return nullptr;
    }
};