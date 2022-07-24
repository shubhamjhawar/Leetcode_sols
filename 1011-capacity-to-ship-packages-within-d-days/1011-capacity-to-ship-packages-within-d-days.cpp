class Solution {
public:
    int numberOfRounds(vector<int>& weights,int capacity){
        
        int trips = 0,curr_load = 0;
        int  n = weights.size();
        for(int i = 0 ; i < n ; i++){
            
            if(curr_load + weights[i] <= capacity){
                curr_load += weights[i];
            }
            else{
                trips++;
                curr_load = weights[i];
            }
        }
        ++trips;
        return trips;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int high = 0,low = INT_MIN,i;
        
        for(i = 0 ; i < weights.size() ; i++) {
            high += weights[i];
            low = max(low,weights[i]);
        }
        
        while(low < high){
            
            int mid = low + (high - low)/2;
            
            if(numberOfRounds(weights,mid) <= days){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        
        return low;
        
    }
};