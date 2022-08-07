typedef pair<int,int> pi;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      priority_queue<pi> pq;
        
      for(int i = 0 ; i < points.size() ; i++){
          int x = points[i][0];
          int y = points[i][1];
          
          int dist = x*x + y*y;
          
          pq.push({dist,i});
          
          if(pq.size() > k){
              pq.pop();
          }
            
      }
    
    
      vector<vector<int>> res;  
      while(pq.size()){
          auto elt = pq.top();
          pq.pop();
          int i = elt.second;
          
          res.push_back(points[i]);
          
      }
        
      return res;
    }
};