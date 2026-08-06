class Solution {
public:
    int calculate(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>>pq;

        for(auto &point:points) {
            int dist = calculate(point);
            if(pq.size() < k) {
                pq.push({dist,point});
            } else if(pq.top().first > dist) {
                pq.pop();
                pq.push({dist, point});
            }
        }

        vector<vector<int>>ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};