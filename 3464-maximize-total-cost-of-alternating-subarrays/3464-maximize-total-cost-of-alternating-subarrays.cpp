class Solution {
public:
typedef long long ll;
ll subseq(vector<int> &nums, bool onlyadd, int idx, vector<vector<ll>> &dp)
{
    if (idx == 0)
        onlyadd = true;
    if (idx > nums.size() - 1)
        return 0;
    ll a = 0, b = 0;

    if (dp[idx][onlyadd] != -1)
        return dp[idx][onlyadd];

    a = nums[idx] + subseq(nums, false, idx + 1, dp); // add
    if (!onlyadd)
    {
        b = subseq(nums, true, idx + 1, dp) - nums[idx];
        a = max(a, b);
    }

    return dp[idx][onlyadd] = a;
}

    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size(); 
        vector<vector<ll>> dp(n+3, vector<ll> (2,-1));
        ll ans = subseq(nums, false, 0, dp);
    return ans;
    }

};