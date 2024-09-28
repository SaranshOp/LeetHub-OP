class Solution
{
public:
    string reverseWords(string s)
    {
        string rever;
        string word;
        stack<string> stk;
        for (int i = 0; i < s.size(); i++)
        {
            while (s[i] != ' ' && i < s.size())
            {
                word += s[i];
                i++;
            }
            if (word != "")
            {
                stk.push(word);
                word = "";
            }
        }
        while (!stk.empty())
        {
            rever += stk.top();
            stk.pop();
            if(!stk.empty())rever += " ";
        }
        return rever;
    }
};