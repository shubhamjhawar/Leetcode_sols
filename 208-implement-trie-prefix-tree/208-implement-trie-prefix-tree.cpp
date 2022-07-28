struct Node{
    Node* links[26];
    bool flag;
    
    bool containsKey(char c){
        return links[c - 'a'] != NULL;
    }
    
    
    void put(char c,Node* node){
        links[c - 'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch - 'a'];
    }
    
    void setEnd(){
    flag  = true;
    }
    
    bool isEnd(){
        return flag;
    }
    
    
};


class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    
    //O(len) of the word
    void insert(string word) {
        Node* curr = root;
        
        for(int i = 0 ; i < word.size() ; i++){
            if(curr->containsKey(word[i]) == false){
                curr->put(word[i],new Node());
            }
            
            curr = curr->get(word[i]);
        }
        
        curr->setEnd();
    }
    
    bool search(string word) {
        Node* curr = root;
        
        for(int i = 0 ; i < word.size() ; i++){
            if(curr->containsKey(word[i]) == false){
                return false;
            }
            //Move to the reference trie
            curr = curr->get(word[i]);
        }
        
        return curr->isEnd();
    }
    
    bool startsWith(string word) {
         Node* curr = root;
        
        for(int i = 0 ; i < word.size() ; i++){
            if(curr->containsKey(word[i]) == false){
                return false;
            }
            //Move to the reference trie
            curr = curr->get(word[i]);
        }
    
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */