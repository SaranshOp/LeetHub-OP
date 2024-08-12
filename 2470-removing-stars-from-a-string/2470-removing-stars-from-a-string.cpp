class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        string str;
        int n = s.length();
        for(int i=0;i<n;i++){
          if(s[i]=='*') {if(!st.empty()) st.pop();}
          else st.push(s[i]);
        }
        while(!st.empty()){
            char c = st.top();
            str+=c;
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;   
    }
};