class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        int ele;
        vector<int> row_min(rows, INT_MAX), col_max(columns);
        for (auto i = 0; i < rows; i++) {
            for (auto j = 0; j < columns; j++) {

                ele = matrix[i][j];

                if (ele < row_min[i]) {
                    row_min[i] = ele;
                }
                if (ele > col_max[j]) {
                    col_max[j] = ele;
                }
            }
        }
        vector<int> lucky_numbers;
        for (auto i = 0; i < rows; i++) {
            int a = row_min[i];
            for (auto j = 0; j < columns; j++) {
                int b = col_max[j];
                if (a == b){
                    lucky_numbers.push_back(matrix[i][j]);
                }
            }
        }
        return lucky_numbers;
    }
};