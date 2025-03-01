class Solution {
public:
    vector<vector<int>> knightMoves = {{-2, 1}, {-1, 2}, {1, 2},   {2, 1},
                                       {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    bool isValid(vector<vector<int>>& grid, int n, int row, int col,
                 int expvalue) {
                    if(expvalue == n*n - 1) {
                        return true;
                    }
                    grid[row][col] = -1 ; //mark as visited
        for (int i = 0; i < knightMoves.size(); i++) {
            for (int j = 0; j < knightMoves[i].size(); j += 2) {
                int r = row + knightMoves[i][j];
                int c = col + knightMoves[i][j + 1];
                if (r >= 0 && c >= 0 && r < n && c < n &&
                    grid[r][c] == expvalue + 1) {
                    if(isValid(grid, n, r, c, expvalue + 1)){
                        return true;
                    }
        grid[row][col] = expvalue; //backtracking
                }
            }
        }
        return false;

    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return isValid(grid,grid.size(),0,0,0);
    }
};