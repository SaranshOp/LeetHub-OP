#include <string>
#include <set>
#include <algorithm>

class Solution {
public:
        string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        while (r > l) {
            //cout << s << " " << l << " " << r << endl;
            while (r >= l && vowels.find(s[l]) == vowels.end()) l++;
            while (r >= l && vowels.find(s[r]) == vowels.end()) r--;
            if(r<l) break;
            swap(s[r], s[l]);
            //cout << s << " " << l << " " << r << endl;
            r--;
            l++;
        }
        return s;
    }
};