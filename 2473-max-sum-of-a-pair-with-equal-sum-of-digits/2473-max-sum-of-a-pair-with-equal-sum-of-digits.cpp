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
        vector<priority_queue<int, vector<int>, greater<int>>> g(82);
        int mx = -1;

        for (int x : nums) {
            int s = calculateDigitSum(x);
            g[s].push(x);
            
            if (g[s].size() > 2) {
                g[s].pop();
            }
        }

        for (auto& h : g) {
            if (h.size() == 2) {
                int a = h.top();
                h.pop();
                int b = h.top();
                mx = max(mx, a + b);
            }
        }

        return mx;
    }
};
