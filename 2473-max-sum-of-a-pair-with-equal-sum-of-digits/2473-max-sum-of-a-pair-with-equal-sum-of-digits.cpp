class Solution {
private:
    int calculateDigitSum(int n) {
        int s = 0;
        while (n > 0) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }

public:
    int maximumSum(vector<int>& nums) {
        vector<pair<int, int>> p;
        
        for (int x : nums) {
            int s = calculateDigitSum(x);
            p.push_back({s, x});
        }
        
        sort(p.begin(), p.end());
        
        int mx = -1;
        
        for (int i = 1; i < p.size(); i++) {
            if (p[i].first == p[i-1].first) {
                int sum = p[i].second + p[i-1].second;
                mx = max(mx, sum);
            }
        }
        
        return mx;
    }
};
