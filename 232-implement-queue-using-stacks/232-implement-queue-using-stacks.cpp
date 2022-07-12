class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(s1.empty() == false){
            s2.push(s1.top());
            s1.pop();
        }
        
        
        s1.push(x);
        
        while(s2.empty() == false){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int elt = s1.top();
        s1.pop();
        return elt;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */