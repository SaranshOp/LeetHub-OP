class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        unordered_map<int, int> map;

        int i = 0, n = skill.size();
        long long sum = 0, ans = 0;

        while (i < n) {
            sum += skill[i];
            i++;
        }

        sum = (sum * 2) / n;

        for (int i = 0; i < n; i++) {
            int target = sum - skill[i];

            if (map[target] > 0) {
                map[target]--;
                ans += (long long)skill[i] * target;
            } else {
                map[skill[i]]++;
            }
        }

        for (auto& entry : map) {
            if (entry.second > 0)
                return -1;
        }

        return ans;
    }
};
