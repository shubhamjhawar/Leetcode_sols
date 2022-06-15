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
    ListNode* deleteDuplicates(ListNode* head) {
       
    if(!head) return NULL;
    ListNode* temp = head;
    ListNode* dummy = new ListNode(-1);
    ListNode* new_head = dummy;
    ListNode* new_tail = dummy;
    while(temp->next){
      if(temp->next && temp->val != temp->next->val){
        new_tail->next = temp;
        new_tail = new_tail->next;
        temp = temp->next;
        new_tail->next = NULL;
        continue;
      }
    
      temp = temp->next;
    }
    new_tail->next = temp;
    
    return new_head->next;  
    }
};