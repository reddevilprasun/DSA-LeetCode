class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        // Create the garph
        for (auto& p : prerequisites) {
            int u = p[1], v = p[0];
            adj[u].push_back(v);
        }
        vector<int> indegree(adj.size(), 0);
        // Calculate the in-degree
        for (int u = 0; u < adj.size(); u++) {
            for (int v : adj[u])
                indegree[v]++;
        }

        queue<int>q;
        // Push all nodes with in-degree 0
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
        return ans.size() == numCourses ? ans : vector<int>();
    }
};