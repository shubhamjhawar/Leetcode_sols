class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool flag = true;
        for(int i = 0 ; i < s.size() ; i++)
      {
            if(s[i] == '(' or s[i] == '[' or s[i] == '{'){
                st.push(s[i]);
            }
            else {
                char c = s[i];
                if(st.empty()){
                    flag = false;
                    break;
                }
                if ((c == ')' && st.top() != '(') || 
                    (c == ']' && st.top() != '[') ||
                    (c == '}' && st.top() != '{'))
                {
                   flag = false;
                   break;
                }
                //which means the () {} [] is found pop them both out
                st.pop();
         }
    }
        
    return st.empty() && flag;
        
 }
};