class Solution {
public:
    vector<int> dirj = {-1, 0, +1, 0};  // Directions for column movement
    vector<int> diri = {0, -1, 0, +1};  // Directions for row movement 
    vector<vector<bool>> isVisited;
    int m, n;

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        isVisited = vector<vector<bool>>(m, vector<bool>(n, false)); 

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) {  
                    return true;
                }
            }
        }
        return false; 
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int p) {
        if (p == word.size()) {
            return true; 
        }
        if (i < 0 || i >= m || j < 0 || j >= n || isVisited[i][j] || board[i][j] != word[p]) {
            return false; 
        }

        isVisited[i][j] = true;
        for (int k = 0; k < 4; k++) { 
            int di = i + diri[k];
            int dj = j + dirj[k];
            if (dfs(board, word, di, dj, p + 1)) { 
                return true;
            }
        }

        isVisited[i][j] = false;
        return false; 
    }
};
