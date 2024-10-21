#include <set>
#include <string>

class Solution {
public:
    int maxUniqueSplit(string s) {
        set<string> unique;
        return maxUniqueSplitHelper(s, 0, unique, 0);
    }
    
    int maxUniqueSplitHelper(const string& s, int start, set<string>& unique, int maxCount) {
        if (start == s.length()) {
            return unique.size();
        } 
        
        for (int i = start + 1; i <= s.length(); i++) {
            string sub = s.substr(start, i - start);
            if (unique.find(sub) == unique.end()) {
                unique.insert(sub);
                maxCount = max(maxCount, maxUniqueSplitHelper(s, i, unique, maxCount));
                unique.erase(sub);
            }
        }
        
        return maxCount;
    }
};

    // bool isinSet(string c, set<string>& uni) {
    //     return uni.find(c) != uni.end();  // return 1 if already present
    // }
    // int maxUniqueSplit(string s) {
    //     set<string> uni;
    //     for (int i = 0; i < s.size(); i++) {
    //         string c = "";
    //         c += s[i];
    //         while (isinSet(c,uni) && i+1 < s.size()) {
    //             i++;
    //             c += s[i];
    //         }
    //         uni.insert(c);
    //     }
    //     return uni.size();
    // }
