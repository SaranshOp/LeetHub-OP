class Solution {
public:
    bool canSortArray(vector<int> &nums) {
        int n = nums.size();
        unordered_map<int, int> bitCount;

        for (int i = 0; i < n; ++i) {
            int count = 0, temp = nums[i];
            while (temp > 0) {
                count += temp & 1;
                temp >>= 1;
            }
            bitCount[nums[i]] = count;
        }

        while (true) {
            bool sorted = true;

            for (int i = 0; i < n - 1; ++i) {
                // Check if the array is sorted
                if (nums[i] > nums[i + 1]) {
                    // Check if counts are different
                    if (bitCount[nums[i]] != bitCount[nums[i + 1]]) {
                        return false;
                    }

                    // Swap the elements to make the array partially sorted
                    swap(nums[i], nums[i + 1]);
                    sorted = false;
                }
            }

            // If the array is sorted, break out of the loop
            if (sorted) {
                break;
            }
        }

        return true;
    }
};