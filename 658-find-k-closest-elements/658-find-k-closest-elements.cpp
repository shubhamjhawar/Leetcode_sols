typedef pair<int,int> pii;
class Solution {
public:
        vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pii> pq;
        vector<int> res;
        for(int i = 0 ; i < arr.size() ; i++){
            pq.push(make_pair(abs(arr[i] - x),arr[i]));
            
            if(pq.size() > k){
                pq.pop();
            }   
        }
        while(!pq.empty()){
            res.push_back(pq.top().second);
                pq.pop();
        }
            
        stable_sort(res.begin(),res.end());
        
        return res;
        
    }
    
};