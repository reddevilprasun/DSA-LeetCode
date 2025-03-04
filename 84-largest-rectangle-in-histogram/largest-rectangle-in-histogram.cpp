class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        int n = ht.size();
        //Right Small Nearest
        stack<int>st;
        vector<int>right(n,0);
        for(int i = n - 1; i >= 0; i-- ) {
            while(!st.empty() && ht[st.top()] >= ht[i]){
                st.pop();
            }
            right[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        //Left Small Nearest 
        stack<int>st2;
        vector<int>left(n,0);
        for(int i = 0; i < n; i++) {
            while(!st2.empty() && ht[st2.top()] >= ht[i]){
                st2.pop();
            }
            left[i] = st2.empty() ? -1 : st2.top();
            st2.push(i);
        }
        int ans = INT_MIN;
        for(int i = 0; i < n ; i++) {
            int r = right[i] == -1 ? n : right[i];
            int l = left[i] == -1 ? -1 : left[i];
                          // hight * width
            int currntArea = ht[i] * ( r - l - 1);
            ans = max(ans,currntArea);
        }
        return ans;
    }
};