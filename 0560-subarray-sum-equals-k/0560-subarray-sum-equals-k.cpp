class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0]++;
        int cnt = 0;
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            long long rem = sum - k;
            if (map.find(rem) != map.end())
                cnt += map[rem];
            map[sum]++;
        }
        return cnt;
    }
};