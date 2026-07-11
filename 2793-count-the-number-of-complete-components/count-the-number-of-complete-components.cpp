class Solution {
public:

   void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited,
             int& vertices, int& edges) {

        visited[node] = true;
        vertices++;
        edges += adj[node].size();

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfs(neighbour, adj, visited, vertices, edges);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);

        int cc = 0;

        
        for (int i = 0; i < n; i++) {

            if (visited[i]) {
                continue;
            }

            int vertices = 0;
            int totalEdges = 0;

            dfs(i, adj, visited, vertices, totalEdges);

            totalEdges /= 2;

            if (totalEdges == (vertices * (vertices - 1)) / 2) {
                cc++;
            }
        }

        return cc;


    }
};