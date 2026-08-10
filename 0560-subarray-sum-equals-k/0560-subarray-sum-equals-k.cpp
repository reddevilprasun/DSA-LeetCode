class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int count = 0;
        int sum = 0;
        m[0] = 1;
        for (int x : nums) {
            sum += x;
            int r = sum - k;
            if (m.count(r))
                count += m[r];
            m[sum]++;
        }

        return count;
    }
};