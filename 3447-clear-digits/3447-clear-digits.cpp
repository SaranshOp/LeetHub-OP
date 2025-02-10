class Solution {
public:
    string clearDigits(string s) {
        int n = s.size() / 2;
        while (n--) {
            auto it = find_if(s.begin(), s.end(), [](char c) { return isdigit(c); });
            if (it!= s.end()) {
                s.erase(it);
                s.erase(it-1);
            } else {
                break;
            }
        }
        return s;
    }
};
