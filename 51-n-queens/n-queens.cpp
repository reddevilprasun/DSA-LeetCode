class Solution {
public:
    bool isSafe(vector<string> &board, int row, int col, int n) { // O(n)
        for (int i = 0; i < n; i++) { // horizontally check
            if (board[row][i] == 'Q')
                return false;
        }
        for (int i = 0; i < n; i++) { // vertically check
            if (board[i][col] == 'Q')
                return false;
        }
        // Left Diagonal check
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        // right Diagonal check
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }
    void nQueen(vector<string>& board, int row, int n,
                vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back({board});
            return;
        }

        for (int j = 0; j < n; j++) {
            if (isSafe(board, row, j, n)) {
                board[row][j] = 'Q';
                nQueen(board, row + 1, n, ans);
                board[row][j] = '.'; // backtracking step
            }
        }
    }
    // TC => O(n!)
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.')); // initilize with '.'
        vector<vector<string>> ans;
        nQueen(board, 0, n, ans);
        return ans;
    }
};