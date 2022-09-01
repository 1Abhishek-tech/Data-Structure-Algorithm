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
  // int lengthLL(ListNode *head){
  //   int l =0;
  //   ListNode *temp = head;
  //   while(temp->next != NULL){
  //     temp = temp->next;
  //     l++;
  //   }
  //   return l;
  // }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * d1 = headA;
      ListNode * d2 = headB;
      
      while(d1 != d2){
        //make a check before pointing d1 one step ahead, as d1 == NULL if it is then it point to other list 's head  
        d1 = d1 == NULL ? headB : d1->next;
        d2 = d2 == NULL ? headA : d2->next;
      }
      
      return d1;
//       int l1 = lengthLL(headA);
//       int l2 = lengthLL(headB);
  
//         int d =0;
//         ListNode* ptr1 = new ListNode(-1);
//         ListNode* ptr2 = new ListNode(-1);
//         if(l1>l2){
//             d = l1 - l2;
//             ptr1 = headA;
//             ptr2 = headB;
//         }
//         else{
//             d = l2 - l1;
//             ptr1 = headB;
//             ptr2 = headA;
//         } 
//         while(d--){
//             ptr1 = ptr1->next;
//         }    
//         while(ptr1!=NULL || ptr2!=NULL){
//             if(ptr1-> next == ptr2->next){
//                 return ptr1->next;
//             }
//             ptr1=ptr1->next;
//             ptr2=ptr2->next;
//         }
//       return NULL;
//       int diff =0;
//       if(n1>n2){
//         diff = n1-n2;
//         while(diff){
//           headA = headA->next;
//           diff--;
//         }
        
//       }
//       else{
//         diff = n2-n1;
//             while(diff){
//           headB = headB->next;
//           diff--;
//         }
//       }
//       while(n1>=0 || n2>=0){
//         if(headA->next == headB->next){
//           return headA->next;
//         }
//         headA = headA->next;
//         headB = headB->next;
//         n1--;
//         n2--;
//       }
//       return NULL;
    }
};