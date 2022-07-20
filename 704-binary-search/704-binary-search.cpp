class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        //divide the search space such as TTTFFF or FFFFTTTT
        //That is F*T* or T*F*
        //find the last F or first T
        int low = 0,high = nums.size()-1;
        //if(arr[mid] < target) this will give F*T* pattern and we need the first T
        while(low < high){
            
            int mid = low + (high - low)/2;
            
            if(nums[mid] >= target){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        
        if(nums[low] == target){
            return low;
        }
        
        return -1;
    }
};