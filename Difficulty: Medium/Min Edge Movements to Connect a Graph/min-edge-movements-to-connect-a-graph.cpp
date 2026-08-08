class Solution {
  public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // Step 1: Quick check
        if(edges.size() < n - 1) return -1; 
        
        // Step 2: Build adjacency list
        vector<vector<int>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        // Step 3: Count components
        vector<bool> vis(n, false);
        int components = 0;
        
        function<void(int)> dfs = [&](int u){
            vis[u] = true;
            for(int v : adj[u]){
                if(!vis[v]) dfs(v);
            }
        };
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                components++;
                dfs(i);
            }
        }
        
        // Step 4: Minimum operations = components - 1
        return components - 1;
    }
};
