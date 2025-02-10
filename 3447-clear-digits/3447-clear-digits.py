class Solution:
    def clearDigits(self, s: str) -> str:
        n = len(s) // 2
        while n:
            ind = next((i for i, c in enumerate(s) if c.isdigit()), None)
            if ind is not None:
                s = s[:ind-1] + s[ind+1:]
            else:
                break
            n -= 1
        return s

# // class Solution {
# // public:
# //     string clearDigits(string s) {
# //         int n = s.size() / 2;
# //         while (n--) {
# //             auto it = find_if(s.begin(), s.end(), [](char c) { return isdigit(c); });
# //             if (it!= s.end()) {
# //                 s.erase(it);
# //                 s.erase(it-1);
# //             } else {
# //                 break;
# //             }
# //         }
# //         return s;
# //     }
# // };
