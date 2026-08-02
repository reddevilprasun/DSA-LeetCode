class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        long long currSum = 0;
        unordered_map<int,int>m;
        for(int right = 0; right < nums.size(); right++) {
            // Absorb current element
            currSum += nums[right];
            m[nums[right]]++;
            // Remove the element leaving the window
            if(right >= k){
                currSum -= nums[right - k];
                m[nums[right - k]]--;
                if(m[nums[right - k]] == 0) m.erase(nums[right - k]);
            }

            // Window is full
            if(right >= k - 1) {
                if(m.size() == k) {
                    maxSum = max(maxSum, currSum);
                }
            }

        }

        return maxSum;
    }
};