class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            int len = r - l;
            int hi = (height[l] > height[r]) ? height[r] : height[l];
            maxi = max(maxi, len*hi);
            (height[l] > height[r]) ? r-- : l++;
        }
        return maxi;
    }
};