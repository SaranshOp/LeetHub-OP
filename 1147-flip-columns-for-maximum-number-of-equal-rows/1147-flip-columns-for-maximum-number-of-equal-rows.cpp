#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(); 
        map<vector<int>, int> matrixMap; 

        for (int i = 0; i < m; i++) { 
            vector<int> vc1, vc0;
            for (int j = 0; j < n; j++) { 
                int e = matrix[i][j];
                if (e == 0) vc0.push_back(j); 
                if (e == 1) vc1.push_back(j);
            }
            matrixMap[vc0]++; 
            matrixMap[vc1]++; 
        }

        int maxi = INT_MIN;
        for (auto it = matrixMap.begin(); it != matrixMap.end(); it++) {
            maxi = max(maxi, it->second);
        }

        return maxi;
    }
};
