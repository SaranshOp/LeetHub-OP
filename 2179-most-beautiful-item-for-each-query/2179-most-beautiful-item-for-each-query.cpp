class Solution {
public:
    // Custom comparator function for sorting the items
    static bool sortf(const std::vector<int>& a, const std::vector<int>& b) {
        if (a[0] < b[0])
            return true; // a should come before b
        if (a[0] > b[0])
            return false;     // b should come before a
        return (a[1] > b[1]); // if a[0] == b[0], sort by second element in
                              // descending order
    }

    vector<int> maximumBeauty(std::vector<std::vector<int>>& items,
                              std::vector<int>& queries) {
        vector<int> ans;
        // Sort the items using the custom comparator
        sort(items.begin(), items.end(), sortf);
        vector<int> prefix(items.size(), 0);
        prefix[0] = items[0][1]; // Initialize the prefix sum
        for (int i = 1; i < items.size(); i++) {
            prefix[i] = max(prefix[i - 1], items[i][1]); // Update the prefix sum
        }
        cout << "items" << endl;
        for (auto i : items)
        {
            cout << " [" << i[0] << "," << i[1] << "]";
        }
        cout << endl;

        for (auto q : queries) {
            int s = 0, e = items.size() - 1;
            // Binary search to find the index of the highest item value less
            // than or equal to query
            while (s < e) {
                int mid = s + (e - s + 1) / 2; // Make mid biased to the right
                if (items[mid][0] <= q) {
                    s = mid; // Valid item found, search right
                } else {
                    e = mid - 1; // Search left
                }
            }

            if (items[s][0] > q) {
                ans.push_back(0); // No item less than or equal to query
            } else {
                // Finding maximum beauty for the valid elements
                int maxBeauty = prefix[s];
                ans.push_back(maxBeauty);
            }
        }

        return ans; // Return the results of beauty for each query
    }
};