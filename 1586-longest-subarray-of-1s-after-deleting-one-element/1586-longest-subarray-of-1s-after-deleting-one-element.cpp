class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int f = 1;
        int r=0,l=0;
        int count = 0, Max_count=0;
        while(r<nums.size()){
            if(nums[r]==1){
                count = r-l+1;
                r++;
            }
            else if(nums[r]==0 && f==1){
                count = r-l+1;
                f = 0;
                r++;
            }
            else if(nums[r]==0 && f==0){
                if(nums[l]==0) f=1;
                l++;
            }
            Max_count = max(count, Max_count);
        }
        return Max_count - 1;
    }
};