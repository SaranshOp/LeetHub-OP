class Solution
{
public:
    int countOfSubstrings(string word, int k)
    {

        int n = word.size();
        unordered_map<char, int> mp;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (auto c : vowels)
        {
            mp[c] = 0;
        }
        int vowel_count = 0;
        int consonent_count = 0;
        int start = 0;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (vowels.find(word[i]) != vowels.end())
            {
                vowel_count++;
                mp[word[i]]++;
            }
            else
            {
                consonent_count++;
            }
            while (consonent_count > k)
            {
                if (vowels.find(word[start]) != vowels.end())
                {
                    vowel_count--;
                    mp[word[start]]--;
                }
                else
                {
                    consonent_count--;
                }
                start++;
            }
            int f = 0;
            //cout << vowel_count << " " << consonent_count << endl;
            if (consonent_count == k && vowel_count >= 5)
            {
                //cout << word.substr(start, i - start + 1) << endl;
                for (auto c : mp)
                {
                    if (c.second == 0)
                    {
                        f = 1;
                        break;
                    }
                }

                if (!f)
                {
                    //cout << "here" << endl;
                    count++;
                    int j = start;
                    unordered_map<char, int> mp1 = mp; 
                    while (!f && j <= i)
                    {
                        if (mp1[word[j]] == 1 || vowels.find(word[j]) == vowels.end())
                        {
                            //cout << "here" << endl;
                            break;
                        }
                        //cout << "j: " << j << " " << word[j] << endl;
                        count++;
                        mp1[word[j]]--;
                        j++;
                    }
                }
            }
        }
        return count;
    }
};