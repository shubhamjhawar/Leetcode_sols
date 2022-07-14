class Solution {
public:
    //Question can be reduced to the max sum subarray of size k,min size sliding window sum of 
    // size k
    int maxScore(vector<int>& cardPoints, int k) {
        
        int N = cardPoints.size();
        int sum_whole = accumulate(cardPoints.begin(),cardPoints.end(),0);
        if(k == N){
            return sum_whole;
        }
        
        //Size of the window as a whole
        int sz = N-k;
        int ans = INT_MAX;
        int i = 0 ;
        int j = 0;
        int sum = 0 ;
        
        while(j < N){
            sum += cardPoints[j];
            
            if(j - i + 1 < sz){
                j++;
            }
            else if(j - i + 1 == sz){
                ans = min(ans,sum);
                sum -= cardPoints[i];
                i++;
                j++;
            }
        }
        
        return (sum_whole - ans);
       
    }
};