/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        unordered_map<Node* ,Node*> mp;
        Node* dummy = new Node(-1);
        Node* new_head = dummy;
        Node* new_tail = dummy;
        while(curr){
            Node* temp_node = new Node(curr->val);
            new_tail->next = temp_node;
            new_tail = new_tail->next;
            mp[curr] = temp_node;
            curr = curr->next;
        }
        
        mp[NULL] = new_tail->next;
        
        curr = head;
        
        while(curr){
            Node* randomptr =  curr->random;
            mp[curr]->random = mp[randomptr];
            curr = curr->next;
        }
        
        return new_head->next;
    }
};