class Solution {
public:
        vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> nums = arr;
        stable_sort(begin(nums), end(nums), [x](const auto a, const auto b){
            return abs(a - x) < abs(b - x);   // sort by distance from x
        });
        nums.resize(k);                        // choose first k elements
        sort(begin(nums), end(nums));           // sort the output in ascending order before returning
        return nums;
    }
    
};