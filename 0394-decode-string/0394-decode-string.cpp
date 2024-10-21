class Solution {
public:
    string decodeString(string s) {
        stack<pair<string,int>>st;
        string ans;
        int count=0;
        for(auto x:s)
        {
            if(x=='[')
            {
                st.push({ans,count});
                ans="";
                count=0;
            }
            else if(x==']')
            {
                auto [str,c]=st.top();
                st.pop();
                int t=c;
                string add;
                while(t--)
                {
                    add+=ans;
                }
                ans=str+add;
            }
            else if(x<='9' and x>='0')
            {
                count=10*count+x-48;//ASCII for '0'
            }
            else
            {
                ans+=x;
            }
        }
        return ans;
    }
};