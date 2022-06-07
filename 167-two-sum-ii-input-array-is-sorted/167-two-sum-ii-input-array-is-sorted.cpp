class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
         vector<int> res;
         int n = numbers.size();
         int low = 0,high = n-1;
        
         while(low < high){
             if(numbers[high] + numbers[low] > target){
                 high--;
             }
             else if(numbers[high] + numbers[low] < target){
                 low++;
             }
             else{
                 res = {low+1,high+1};
                 break;
             }
         }
        
        return res;
        
    }
};