class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res;
        
        
        //F*T* pattern
        //arr[mid] >= target
        //First T is the element we need
        int n = nums.size();
        if(nums.size() == 0) return {-1 , -1};
        int low = 0 ,high = n-1;
        
        while(low < high){
            
           int mid =  low + (high-low)/2;
            
            if(nums[mid] >= target){
                high = mid;
            }
            else{
                low = mid+1;
            }
             
        }
        if(nums[low] == target){
            res.push_back(low);
        }
        else{
            return {-1,-1};
        }
        
        
        //F*T*
        //arr[mid] > target
        //Last F
        
        low = 0 ;
        high = n-1;
        
        while(low < high){
            
           int mid =  low + (high-low+1)/2;
            
            if(nums[mid] > target){
                high = mid-1;
            }
            else{
                low = mid;
            }
             
        }
        res.push_back(low);
        
        return res; 
    }
};