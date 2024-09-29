class Solution
{
public:
    bool isVowel(char c)
    {
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') ||
               (c == 'u');
    }
    int countOfSubstrings(string word, int k)
    {
        int ans = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < word.size(); i++)
        {
            //cout << "i: " << i << endl;
            int cCount = 0, vCount = 0;
            mp.clear(); // was missing this line
            for (int j = i; j < word.size(); j++)
            {
                //cout << word[j] << " ";
                if (isVowel(word[j]))
                {
                    mp[word[j]]++;
                    if (mp[word[j]] == 1)
                        vCount++;
                }
                else
                {
                    cCount++;
                }
                //cout << vCount << " " << cCount << endl;
                if (vCount == 5 && cCount == k)
                {
                    ans++;
                    //cout << ans << endl;
                }
                if (cCount > k)
                    break;
            }
        }
        return ans;
    }
};