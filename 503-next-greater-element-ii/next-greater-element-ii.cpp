class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, -1);
        stack<int>st;
        for(int i = 2 * n ; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i % n]){
                st.pop();
            }
            st.empty() ? ans[i % n] = -1 : ans[i % n] = nums[st.top()];
            st.push(i % n);
        }
        return ans;
    }
};