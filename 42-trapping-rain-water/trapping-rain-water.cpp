class Solution {
public:
    int trap(vector<int>& ht) {
        int n = ht.size();
        vector<int> right(n);
        vector<int> left(n);
        right[n - 1] = ht[n - 1];
        left[0] = ht[0];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], ht[i]); 
        }
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], ht[i]);
        }
        int ans = 0;  
        for(int i = 0 ; i < n ; i++) {
            ans += min(left[i], right[i]) - ht[i];
        }
        return ans;
    }
};