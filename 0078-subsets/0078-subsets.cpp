class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&arr, vector<int>&set, int i) {
        //Base case
        if(i == arr.size()) {
            ans.push_back(set);
            return;
        }
        //Include
        set.push_back(arr[i]);
        helper(arr,set,i+1);
        //Exclude
        set.pop_back();
        helper(arr,set,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>set;
        helper(nums, set,0);
        return ans;
    }
};