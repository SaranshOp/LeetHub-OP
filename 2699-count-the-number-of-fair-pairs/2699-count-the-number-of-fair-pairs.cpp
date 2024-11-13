

class Solution {
    typedef long long ll;

public:
    long long BSearch(vector<int> &nums, ll st, ll en, ll mini, ll maxi) {
        int mid;
        int s = st, e = en; /// 0 1 4 4 5 mini=3
        while (s < e) {
            mid = s + (e - s) / 2; //  
            if (nums[mid] < mini) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        if(s==st) s++;  
        int ans1 = en-s+1;
        s=st;e=en;  // 0 1 4 4 5  maxi = 1;
        while (s < e) {
            mid = s + (e - s + 1) / 2;
            if (nums[mid] > maxi) {
                e = mid - 1; //  go left
            } else {
                s = mid;
            } 
        } 
        if(s==en) s--;
        int ans2 = s - st+1;
        cout << "ans1 " << ans1 << " ans2 " << ans2 << endl;
        return ans1+ans2-1;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long l = 0, r = n - 1, ans = 0,i=0;
        while (l < r) {
            ll pairsum = nums[l] + nums[r];
            if (pairsum > upper)
                r--;
            else if (pairsum < lower)
                l++;
            else if (pairsum <= upper && pairsum >= lower) {
                ans += BSearch(nums, l, r, lower - nums[l], upper - nums[r]);
                l++;
                r--;
                cout << ++i << " " << ans<<" "<<endl;
            }
        }
        return ans;
    }
};
// 0 1 7 4 4 5  lw= 3 upp=6
// 0 1 4 4 5 7                 0 5

// sort
//
// Two Pointer -> 2 conditions
//-100   -1 0 1 2 5 7 9 13   14      lw = 4 up = 12