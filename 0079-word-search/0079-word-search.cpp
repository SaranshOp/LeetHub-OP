class Solution {
public:
    vector<int> dirj = {-1, 0, +1, 0};  // Directions for column movement (left, down, right, up)
    vector<int> diri = {0, -1, 0, +1};  // Directions for row movement (up, left, down, right)
    vector<vector<bool>> isVisited;
    int m, n;

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        isVisited = vector<vector<bool>>(m, vector<bool>(n, false)); // Initialize visited array

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) {  // Start DFS from each cell
                    return true; // If the word is found, return true
                }
            }
        }
        return false; // If the word is not found after exploring all cells
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int p) {
        if (p == word.size()) {
            return true; // All characters in the word are matched
        }
        if (i < 0 || i >= m || j < 0 || j >= n || isVisited[i][j] || board[i][j] != word[p]) {
            return false; // Out of bounds or already visited or character does not match
        }

        isVisited[i][j] = true; // Mark the cell as visited

        for (int k = 0; k < 4; k++) { // Explore all four directions
            int di = i + diri[k];
            int dj = j + dirj[k];
            if (dfs(board, word, di, dj, p + 1)) { // Recursively call DFS
                return true;
            }
        }

        isVisited[i][j] = false; // Backtrack: unmark the cell
        return false; // Return false if the word is not found
    }
};
