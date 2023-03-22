// Method 1: BFS
/*
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        vector<vector<pair<int, int>>> gr(n+1);

        for(auto edge : roads) {
            gr[edge[0]].push_back({edge[1], edge[2]}); // u -> {v, dis}
            gr[edge[1]].push_back({edge[0], edge[2]});   // v -> {u, dis}
        }

        vector<int> visited(n+1, 0);
        queue<int> q;
        q.push(1); visited[1] = 1;

        while(!q.empty()) {
            int node = q.front(); q.pop();

            for(auto &[v, dis] : gr[node]) {
                ans = min(ans, dis);

                if(visited[v] == 0) {
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};
*/

//-----------------------------------------------------------------------------
// Method 2: DFS
class Solution {
public:
    int dfs(int node, int ans, vector<vector<pair<int, int>>> &gr, vector<int> &visited) {
        visited[node] = 1;

        for(auto &[v, dis] : gr[node]) {
            ans = min(ans, dis);

            if(visited[v] == 0) {
                visited[v] = 1;

                ans = min(ans, dfs(v, ans, gr, visited));
            }
        }

        return ans;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;

        vector<vector<pair<int, int>>> gr(n+1);

        for(auto edge : roads) {
            gr[edge[0]].push_back({edge[1], edge[2]});
            gr[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<int> visited(n+1, 0);

        return dfs(1, ans, gr, visited);
    }
};