class Solution {
public:
typedef long long ll;
    long long maxPoints(vector<vector<int>>& points) {
        int n = points[0].size();
        int m = points.size();

        vector<ll> prevdp(n, 0);
        for (int i=0; i<n;i++) {
            prevdp[i] = points[0][i];
        }

        for (int j=1; j<m; j++) {
            vector<ll> rightmaxdp(n, 0), leftmaxdp(n, 0);

            leftmaxdp[0] = prevdp[0];
            for (int i=1;i<n;i++) {
                leftmaxdp[i] = max(leftmaxdp[i - 1] - 1, prevdp[i]);
            }
            rightmaxdp[n-1] = prevdp[n-1];
            for (int i=n-2;i>=0;i--) {
                rightmaxdp[i] = max(rightmaxdp[i + 1] - 1, prevdp[i]);
            }
            for (int i=0;i<n;i++) {
                prevdp[i] = points[j][i] + max(leftmaxdp[i], rightmaxdp[i]);
            }
        }
        ll maxi = *max_element(prevdp.begin(), prevdp.end());
        return maxi;
    }
};