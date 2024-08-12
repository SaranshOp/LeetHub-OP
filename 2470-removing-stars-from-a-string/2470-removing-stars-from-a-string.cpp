class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        stack<char>st2;
        string str;
        int n = s.length();
        for(int i=0;i<n;i++){
          if(s[i]=='*') {if(!st.empty()) st.pop();}
          else st.push(s[i]);
        }
        while(!st.empty()){
            char c = st.top();
            st2.push(c);
            st.pop();
        }
        while(!st2.empty()){
            char c = st2.top();
            str+=c;
            st2.pop();
        }
        return str;   
    }
};