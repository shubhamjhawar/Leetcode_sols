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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> mp;
        ListNode* list_head1 = headA;
        while(list_head1 != NULL){
            mp[list_head1]++;
            list_head1 = list_head1->next;
        }
        bool flag  = true;
        ListNode* list_head2 = headB;
        while(list_head2 && flag){
            if(mp.find(list_head2) != mp.end()){
                flag = false;
                break;
            }
            list_head2 = list_head2->next;
        }
        return list_head2;
    }
};