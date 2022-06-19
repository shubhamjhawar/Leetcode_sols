typedef pair<int, int> pi;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> mp;
        for(auto x : nums){
            mp[x]++;
        }
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;

        for(auto x : mp){
           pq.push({x.second,x.first});
            
           if(pq.size() > k){
               pq.pop();
           }
        }
        
        while(pq.size()){
            auto x = pq.top();
            pq.pop();                
            res.push_back(x.second);
        }
        
        return res;
    }
};