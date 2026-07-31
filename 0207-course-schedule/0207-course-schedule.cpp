class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        queue<int>q;
        int processed = 0;
        // Create the Graph
        for(auto &p:prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        // Calculate the indegree
        for(int i = 0; i < n; i++) {
            for(int v:adj[i]) indeg[v]++;
        }
        // Push all indgree = 0 to the queue
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int curr = q.front();
            q.pop(); processed++;

            for(int v:adj[curr]){
                indeg[v]--;
                if(indeg[v] == 0) q.push(v);
            }
        }

        return processed == n;
    }
};