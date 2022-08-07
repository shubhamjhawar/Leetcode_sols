class Solution {
public:
    int lastStoneWeight(vector<int>&  nums) {
        priority_queue<int> pq;
        
        for(auto x: nums){
            pq.push(x);
        }
        
        while(pq.size() > 1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            
            if(y - x > 0){
                pq.push(y-x);
            }
        }
        
        if(pq.size()){
            return pq.top();
        }else{
            return 0;
        }
        
    }
};