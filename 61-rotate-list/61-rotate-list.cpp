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
        
        if(!head) 
            return head;//When null return 
       
        
        ListNode* new_tail = head;
        
        int count = 1;//number of nodes
        
        while(new_tail->next){
            new_tail = new_tail->next;
            count++;
        }
        
 
        if(k%count == 0) return head;
        //Number of rotations is same it is the same linked list as a whole
        //Optimisation of  the linked list
        
        int move_forward = count - k%count;
        int i = 1;
        ListNode* temp = head;
        while(i < move_forward){
            i++;
            temp = temp->next;
        }
        
        ListNode* new_head = temp->next;
        temp->next = NULL;
        
        new_tail->next = head;
            
        return new_head;
    }
};