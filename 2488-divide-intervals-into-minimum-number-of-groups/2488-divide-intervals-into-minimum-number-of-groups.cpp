class Solution {
public:
    typedef long long ll;
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n==1) return 1;



        vector<pair<ll, ll>> event;
        for (auto i = 0; i < n; i++) {
            ll a = intervals[i][0];
            ll b = intervals[i][1];
            event.push_back({a, 1});
            event.push_back({b+1, -1});
        }
        auto comp = [](auto a, auto b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        };
        sort(event.begin(), event.end(), comp);

        ll maxGroups = 0, currGroups = 0;
        for (auto& e : event) {
            currGroups += e.second; 
            maxGroups = max(maxGroups, currGroups);
        }

        return maxGroups;
    }
};