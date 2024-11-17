class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0; // Use long long for sum to prevent overflow
        int minL = INT_MAX; // Initialize minL to the maximum possible integer value
        deque<pair<long long, int>> dq; // Use a deque to store pairs of (cumulative sum, index)

        // Iterate through the array
        for (int i = 0; i < n; i++) {
            sum += nums[i];

            // Check if the sum from the start to current index is enough
            if (sum >= k) {
                minL = min(minL, i + 1);
            }

            // Remove elements from the deque if they can form a valid subarray
            while (!dq.empty() && sum - dq.front().first >= k) {
                minL = min(minL, i - dq.front().second);
                dq.pop_front();
            }

            // Maintain the deque in increasing order of cumulative sum
            while (!dq.empty() && sum < dq.back().first) {
                dq.pop_back();
            }

            dq.push_back({sum, i});
        }

        // Return -1 if no valid subarray found, otherwise return minL
        return minL == INT_MAX ? -1 : minL;
    }
};
