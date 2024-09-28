class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int countZ = 0;
        int l=0, Max_count=0;
        for (int i = 0; i < nums.size(); i++){
            countZ += (nums[i] == 0);
            while(countZ > 1){
                countZ -= (nums[l++] == 0);
            }
            Max_count = max( i-l+1 , Max_count);

        }
        return Max_count -1;
}
};