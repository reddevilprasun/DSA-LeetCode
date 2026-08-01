class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int R = m.size();
        int C = m[0].size();

        int top = 0, left = 0;
        int right = C - 1, bottom = R - 1;

        vector<int>ans;
        while(top <= bottom && left <= right) {
            for(int c = left; c <= right ; c++) {
                ans.push_back(m[top][c]);
            }
            top++;

            for(int r = top; r <= bottom; r++) {
                ans.push_back(m[r][right]);
            }
            right--;

            if(top <= bottom){
                for(int c = right; c >= left; c--){
                    ans.push_back(m[bottom][c]);
                }
                bottom--;
            }

            if(left <= right){
                for(int r = bottom; r >= top; r--){
                    ans.push_back(m[r][left]);
                }
                left++;
            }
        }
        return ans;
    }
};