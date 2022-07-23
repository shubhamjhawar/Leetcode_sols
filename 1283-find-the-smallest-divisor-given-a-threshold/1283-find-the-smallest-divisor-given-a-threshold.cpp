class Solution {
public:
    int calculate(vector<int>& nums,int k){
        
        int cal = 0;
        for(auto& x : nums){  
            cal += ceil((float)x/(k));
        }
        
        return cal;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        
        //F*T*
        // sum_after_threshold[i] <= threshold
        while(low < high){
            
            int mid = low + (high - low)/2;
            
            if(calculate(nums,mid) <= threshold){
                 high = mid;
            }else{
                 low = mid+1;
            }
            
            
        }
        
        return low;
        
    }
};