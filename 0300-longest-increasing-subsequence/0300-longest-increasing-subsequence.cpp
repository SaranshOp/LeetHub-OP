class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        for (auto i : nums) {
            if (res.empty()) {
                res.push_back(i);
                continue;
            }
            auto it = res.end() - 1;
            if (i > *it)
                res.push_back(i);
            else {
                auto min = lower_bound(res.begin(), res.end(), i);
                *min = i;
            }
        }
        return res.size();
    }
};

// class Solution:  # 68 ms, faster than 93.92%
//     def lengthOfLIS(self, nums: List[int]) -> int:
//         sub = []
//         for x in nums:
//             if len(sub) == 0 or sub[-1] < x:
//                 sub.append(x)
//             else:
//                 idx = bisect_left(sub, x)  # Find the index of the first element >= x
//                 sub[idx] = x  # Replace that number with x
//         return len(sub)