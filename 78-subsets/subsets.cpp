class Solution {
public:
    //O(n * 2 ^ n)
    void getAllSubset(vector<int>& arr, vector<int>& ans, int i,
                      vector<vector<int>>& all) {
        if (i == arr.size()) {
            all.push_back({ans});
            return;
        }
        //include
        ans.push_back(arr[i]);
        getAllSubset(arr, ans, i + 1, all);
        //exclude 
        ans.pop_back(); //backtracking
        getAllSubset(arr, ans, i + 1, all);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;
        getAllSubset(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};