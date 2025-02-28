class Solution {
public:
    void getAllSubset(vector<int>& arr, vector<int>& ans, int i,
                      vector<vector<int>>& all) {
        if (i == arr.size()) {
            all.push_back({ans});
            return;
        }
        ans.push_back(arr[i]);
        getAllSubset(arr, ans, i + 1, all);
        ans.pop_back();
        int idx = i + 1;
        while (idx < arr.size() && arr[idx - 1] == arr[idx])
            idx++;
        getAllSubset(arr, ans, idx, all);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allSubsets;
        vector<int> ans;
        getAllSubset(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};