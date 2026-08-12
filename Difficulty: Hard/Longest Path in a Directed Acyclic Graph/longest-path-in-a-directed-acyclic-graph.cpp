class Solution {
  public:
    void topoSortUtil(int u, vector<vector<pair<int,int>>>& adj, vector<int>& visited, stack<int>& st) {
        visited[u] = 1;
        for(auto &p : adj[u]) {
            int v = p.first;
            if(!visited[v]) topoSortUtil(v, adj, visited, st);
        }
        st.push(u);
    }
    
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        // Step 1: Build adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        
        // Step 2: Topological sort
        vector<int> visited(V,0);
        stack<int> st;
        for(int i=0;i<V;i++) {
            if(!visited[i]) topoSortUtil(i, adj, visited, st);
        }
        
        // Step 3: Initialize distances
        vector<int> dist(V, INT_MIN);
        dist[src] = 0;
        
        // Step 4: Relax edges in topo order
        while(!st.empty()) {
            int u = st.top(); st.pop();
            if(dist[u] != INT_MIN) {
                for(auto &p : adj[u]) {
                    int v = p.first, w = p.second;
                    dist[v] = max(dist[v], dist[u] + w);
                }
            }
        }
        
        return dist;
    }
};
