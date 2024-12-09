class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = nums.size();
        //set<pair<int, int>> indices;
        vector<bool> ans;
        vector<int> prefix;
        int num = 0;

        prefix.push_back(num);
        int p = nums[0] % 2, p1;

        for (int i = 1; i < n; i++) {
            p1 = nums[i] % 2;
            if (p == p1) {
                prefix.push_back(++num);
            } else {
                prefix.push_back(num);
            }
            p = p1;
        }

        for (auto q : queries) {
            if (prefix[q[0]] == prefix[q[1]]) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};
