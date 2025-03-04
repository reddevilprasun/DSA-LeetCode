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
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        //Left Small Nearest 
        vector<int>left(n,0);
        for(int i = 0; i < n; i++) {
            while(!st.empty() && ht[st.top()] >= ht[i]){
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        int ans = INT_MIN;
        for(int i = 0; i < n ; i++) {
            int width = right[i] - left[i] - 1;
                          // hight * width
            int currntArea = ht[i] * width;
            ans = max(ans,currntArea);
        }
        return ans;
    }
};