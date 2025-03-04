class Solution {
public:
    int trap(vector<int>& ht) {
        int n = ht.size();
        // vector<int> right(n);
        // vector<int> left(n);
        // right[n - 1] = ht[n - 1];
        // left[0] = ht[0];
        // for (int i = n - 2; i >= 0; i--) {
        //     right[i] = max(right[i + 1], ht[i]); 
        // }
        // for (int i = 1; i < n; i++) {
        //     left[i] = max(left[i - 1], ht[i]);
        // }
        int lmax = -1, rmax = -1;
        int l = 0, r = n -1;
        int ans = 0;  
        while(l <r) {
            lmax = max(lmax, ht[l]);
            rmax = max(rmax,ht[r]);
            if(lmax < rmax){
                ans += lmax - ht[l++];
            } else {
                ans += rmax - ht[r--];
            }
        }
        return ans;
    }
};