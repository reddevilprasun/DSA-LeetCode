class Solution {
public:
    set<vector<int>> s;
    void getAllCombination(vector<int>& arr, vector<vector<int>>& ans, int idx,
                           int target, vector<int>& combination) {
        if (idx == arr.size() || target < 0) {
            return;
        }
        if (target == 0) {
            if (s.find(combination) == s.end()) {
                ans.push_back(combination);
                s.insert(combination);
            }
            return;
        }
        combination.push_back(arr[idx]);
        // single
        getAllCombination(arr, ans, idx + 1, target - arr[idx], combination);
        // multiple
        getAllCombination(arr, ans, idx, target - arr[idx], combination);
        combination.pop_back();
        // exclusion
        getAllCombination(arr, ans, idx + 1, target, combination);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        getAllCombination(candidates, ans, 0, target, combination);
        return ans;
    }
};