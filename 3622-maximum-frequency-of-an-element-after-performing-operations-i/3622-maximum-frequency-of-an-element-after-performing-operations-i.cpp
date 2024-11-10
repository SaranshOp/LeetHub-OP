class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {

        sort(nums.begin(), nums.end());
        int l = 0, r = 0, n = nums.size(), ans = INT_MIN;
        unordered_map<int, int> count;

        for (auto num : nums)
            count[num]++;

        for (int i = 0; i < n; i++) {
            int ele = nums[i];
            while (ele - nums[l] > k) {
                l++;
            }
            while (r < n && nums[r] - ele <= k) {
                r++;
            }
            int totsim = r - l;
            int diff = totsim - count[nums[i]];
            int changes = min(diff, numOperations);
            ans = max(ans, changes + count[nums[i]]);
        }
        l = 0;
        for (r = 0; r < n; r++) {
            int mid = (nums[l] + nums[r]) /
                      2; // Calculate hypothetical midpoint

            // Adjust left pointer to ensure midpoint is within `k` range from
            // both ends
            while (mid - nums[l] > k || nums[r] - mid > k) {
                l++;
                mid = (nums[l] + nums[r]) / 2;
            }

            // Update ans with maximum achievable frequency with the
            // hypothetical midpoint
            ans = max(ans, min(r - l+1, numOperations));
        }

        return ans;
    }
};