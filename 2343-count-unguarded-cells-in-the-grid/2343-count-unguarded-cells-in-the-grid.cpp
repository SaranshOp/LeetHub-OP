#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
   
        vector<int> diri = {0, 0, 1, -1};
        vector<int> dirj = {-1, 1, 0, 0};

        vector<vector<bool>> isGuarded(m, vector<bool>(n, true));
        set<pair<int, int>> obstacles; 

        for (auto& g : guards) {
            obstacles.insert({g[0], g[1]});
            isGuarded[g[0]][g[1]] = false; 
        }
        for (auto& w : walls) {
            obstacles.insert({w[0], w[1]});
            isGuarded[w[0]][w[1]] = false;
        }

        for (auto& g : guards) {
            int i = g[0];
            int j = g[1];
            for (int d = 0; d < 4; d++) {
                int di = i;
                int dj = j;

            
                while (true) {
                    di += diri[d];
                    dj += dirj[d];

               
                    if (di < 0 || di >= m || dj < 0 || dj >= n) break;

              
                    if (obstacles.find({di, dj}) != obstacles.end()) break;

                
                    isGuarded[di][dj] = false;
                }
            }
        }


        int unguardedCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isGuarded[i][j]) unguardedCount++;
            }
        }

        return unguardedCount;
    }
};
