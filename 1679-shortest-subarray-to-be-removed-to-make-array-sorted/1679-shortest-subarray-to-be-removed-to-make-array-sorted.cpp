class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int right = arr.size() - 1;
        while (right > 0 && arr[right] >= arr[right - 1]) {
            right--;
        }

        int ans = right;
        int left = 0;
        while (left < right && (left == 0 || arr[left - 1] <= arr[left])) {
            // find next valid number after arr[left]
            while (right < arr.size() && arr[left] > arr[right]) {
                right++;
            }
            // save length of removed subarray
            ans = min(ans, right - left - 1);
            left++;
        }
        return ans;
    }
};
// class Solution {
// public:
//     int findLengthOfShortestSubarray(vector<int>& arr) {
//         for()
//         // first devide the array into 3 parts;
//         // put l, r pointers into array

//         // we hve to assume and simulate cond where left // right subaarray is sorted. 
//         //  
//     }
// };

// // 0 1 2 3 ,,, 10 4 2 1 0 1 2 ,,, 3 5 