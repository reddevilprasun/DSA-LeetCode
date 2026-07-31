class Solution {
public:
    int n, m;
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int idx) {
        if (idx == word.length() - 1)
            return true; // Base case
        char temp = board[r][c];
        board[r][c] = '.'; // mark visited;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                board[nr][nc] == word[idx + 1]) {
                if (dfs(board, word, nr, nc, idx + 1))
                    return true;
            }
        }

        board[r][c] = temp; // Backtrack
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
};