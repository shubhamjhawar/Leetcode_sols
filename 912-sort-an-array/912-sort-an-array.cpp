class Solution {
public:
void insertatposn(vector<int>& arr,int val){
    //base condition
    if(arr.size() == 0 || arr[arr.size() -1] <= val){
        arr.push_back(val);
        return;
    }
    
    //Hypothesis
    int value = arr[arr.size() -1];
    arr.pop_back();
    insertatposn(arr,val);
    arr.push_back(value);
    
}
void insertion_sort(vector<int>& arr){
    //Base condition
    if(arr.size() == 1)
        return;
    
    
    //Get the smaller input
    //Hypothesis step
    int val = arr[arr.size()-1];
    arr.pop_back();
    insertion_sort(arr);
    
    //Induction step
    insertatposn(arr,val);   
}

vector<int> sortArray(vector<int>& nums) {
        
        int n = nums.size();
        //insertion_sort(nums);
        sort(nums.begin(),nums.end());
        return nums;
        
   }
};