class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();  
        unordered_map<string, int> matrixMap;  

        for (int i = 0; i < m; ++i) {  
            
            string original = "", flipped = "";
            for (int j = 0; j < n; ++j) {
                original += to_string(matrix[i][j]);  
                flipped += to_string(1 - matrix[i][j]);
            }

          
            matrixMap[original]++;
            matrixMap[flipped]++;
        }

        int maxi = 0;  
        for (auto it = matrixMap.begin(); it != matrixMap.end(); ++it) {
            maxi = max(maxi, it->second);
        }

        return maxi;
    }
};
