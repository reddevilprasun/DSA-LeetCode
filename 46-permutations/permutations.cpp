class Solution {
public:
    void getAllPermute(vector<int>& arr, int idx,
                       vector<vector<int>>& allPermute) {
        if (idx == arr.size()) { // base case
            allPermute.push_back({arr});
            return;
        }

        for (int i = idx; i < arr.size(); i++) {
            swap(arr[idx], arr[i]);
            getAllPermute(arr, idx + 1, allPermute);
            swap(arr[idx], arr[i]); // backtracking
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> allPermute;
        getAllPermute(nums, 0, allPermute);
        return allPermute;
    }
};