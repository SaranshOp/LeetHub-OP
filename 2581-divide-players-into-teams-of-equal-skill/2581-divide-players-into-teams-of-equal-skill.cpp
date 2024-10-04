class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        if (n == 2)
            return skill[0] * skill[1];
        sort(skill.begin(), skill.end());
        int s = skill[0] + skill[n - 1];
        long long ans = 0;
        for (int i = 0; i < n / 2; i++) {
            int a = skill[i];
            int b = skill[n - i - 1];
            if (a + b != s)
                return -1;
            ans += a * b;
        }
        return ans;
    }
};