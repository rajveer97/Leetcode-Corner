class Solution {
public:

    // standard dfs
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src) {
        visited[src] = true;

        for(auto i : adj[src]) {
            if(!visited[i]) {
                dfs(adj, visited, i);
            }
        }
    }


    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)  // if total no. of wires is less than n-1, then not possible
            return -1; 
        
        vector<vector<int>> adj(n);

        for(auto edge : connections) 
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int components = 0;

        vector<bool> visited(n, false);
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(adj, visited, i);
                components++;
            }
        }

        return components - 1;
    }
};