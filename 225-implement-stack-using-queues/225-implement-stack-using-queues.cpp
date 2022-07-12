class MyStack {
private:
    queue<int> q1;
    int curr_size;
public:
    MyStack() {
      curr_size = 0;
    }
    
    void push(int x) {
        
        curr_size++;
        q1.push(x);
        int i = 0;
        while(i < q1.size()-1){
            q1.push(q1.front());
            q1.pop();
            i++;
        }
        
    }
    
    int pop() {
        int ans = -1;
        if(q1.size() > 0){
            ans = q1.front();
            q1.pop();
            curr_size--;
        }
        
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};