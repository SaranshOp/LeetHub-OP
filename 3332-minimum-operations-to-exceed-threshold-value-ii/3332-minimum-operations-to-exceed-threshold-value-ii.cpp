class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq(nums.begin(), nums.end());
        int ops = 0;

        while (pq.top() < k) {
            long a = pq.top();
            pq.pop();
            long b = pq.top();
            pq.pop();
            pq.push(min(a, b) * 2 + max(a, b));
            ops++;
        }
        return ops;
    }
};
