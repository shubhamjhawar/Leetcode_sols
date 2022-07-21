class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(),i ;
        stack<pair<int,int>> st;
        vector<int> NSLindex(n,-1);
        //will store the height[i] and the NGL index
        for(i = 0 ; i < n; i++ ){
            
            while(!st.empty() && heights[i] <= st.top().first){
                st.pop();
            }
            
            if(st.empty()){
                NSLindex[i] = -1;
            }
            else{
                NSLindex[i] = st.top().second;
            }
            
            st.push({heights[i],i});
            
        }
        while(!st.empty()){
            st.pop();
        }
        
        vector<int> NSRindex(n,n);
        for(i = n-1 ; i >= 0; i-- ){
            
            while(!st.empty() && heights[i] <= st.top().first){
                st.pop();
            }
            
            if(!st.empty()){
               NSRindex[i] = st.top().second;
            }
            
            st.push({heights[i],i});
            
        }
        int max_area = 0;
        for(int i = 0 ; i < n ; i++){
            //cout << NSRindex[i] << " " << NSLindex[i] << "  " << heights[i] << endl;
            int width = NSRindex[i]-NSLindex[i]-1;
            
            int area = width*heights[i];
            
            max_area = max(area,max_area);
            
            
            
        }
        
        
        return max_area;
        
        
    
    }
};