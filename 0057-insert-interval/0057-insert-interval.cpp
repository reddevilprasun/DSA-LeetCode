class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;

        for(auto interval:intervals) {
            // Case 1. intervals befor the new interval
            if(interval[1] < newInterval[0]) {
                ans.push_back(interval);
            } 
            // Case 2. interval after the new interval
            else if(newInterval[1] < interval[0]) {
                ans.push_back(newInterval);
                newInterval = interval;
            }
            // Case 3. Over lap
            else {
                newInterval[0] = min(interval[0], newInterval[0]);
                newInterval[1] = max(interval[1], newInterval[1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};