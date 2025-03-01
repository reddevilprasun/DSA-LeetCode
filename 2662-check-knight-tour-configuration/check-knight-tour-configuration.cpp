class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int n, int row, int col, int expvalue) {
        if(row < 0 || col < 0 || row >= n || col >= n || grid[row][col] != expvalue) return false;
        if(expvalue == n*n - 1) return true;
        
        grid[row][col] = -1; //mark as visited
        bool ans1 = isValid(grid,n,row - 2, col + 1,expvalue + 1);
        bool ans2 = isValid(grid,n,row - 2, col - 1,expvalue + 1);
        bool ans3 = isValid(grid,n,row + 2, col + 1,expvalue + 1);
        bool ans4 = isValid(grid,n,row + 2, col - 1,expvalue + 1);
        bool ans5 = isValid(grid,n,row + 1, col - 2,expvalue + 1);
        bool ans6 = isValid(grid,n,row - 1, col - 2,expvalue + 1);
        bool ans7 = isValid(grid,n,row - 1, col + 2,expvalue + 1);
        bool ans8 = isValid(grid,n,row + 1, col + 2,expvalue + 1);
        
        grid[row][col] = expvalue; //backtracking
        return 
        ans1 || 
        ans2 || 
        ans3 || 
        ans4 || 
        ans5 || 
        ans6 || 
        ans7 || 
        ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return isValid(grid, grid.size(), 0, 0, 0);
    }
};