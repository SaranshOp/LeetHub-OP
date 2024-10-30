class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // PREFIXSUM concept DP
        vector<int> dp(n,1);
        for(int i=0; i<n; i++){
            int p = nums[i];
            for(int j=0;j<i;j++){
                int o = nums[j];

                if(o < p && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};