class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows,i,j;
        vector<vector<int>> res;
//         if(n == 1){ 
//             res[0].push_back(1);
//             return res;
//         }
        
//         if(n == 2){
//             res[0].push_back({1});
//             res[1].push_back({1,1});
//             return res; 
//         }
       vector<int> temp;
       temp.push_back(1);
       res.push_back(temp);
       if( n == 1) return res;
       
       temp.push_back(1);
       res.push_back(temp);
       if( n == 2 ) return res;
        for(i = 2 ; i < n ; i++){
            vector<int> temp;
            temp.push_back(1);
            for(j = 0 ; j < res[i-1].size()-1; j++){
                temp.push_back(res[i-1][j] + res[i-1][j+1]);
            }
            temp.push_back(1);
            res.push_back(temp);
        }
        
        
        return res;

    }
};