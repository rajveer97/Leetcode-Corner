class Solution {
public:
    void bfs(vector<vector<pair<int, int>>>& graph, vector<int>& res){
        int level = -1;
        queue<pair<int, int>> q;
        q.push({0, -1});                // queue = {vertex, color}
                         
        while(!q.empty()){
            int s = q.size();
            level++;

            while(s--){
                auto u = q.front();    q.pop();
                res[u.first] = min(res[u.first], level);

                for(auto& v : graph[u.first]){
                    if(v.first != -1 && u.second != v.second){
                        q.push(v);
                        v.first = -1;                            // better way to mark some {vertex, color} visited, just remove graph edge itself
                    }
                }
            }
        }
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> res(n, INT_MAX);
        vector<vector<pair<int, int>>> graph(n);
        
        for(auto edge : redEdges)  graph[edge[0]].push_back({edge[1], 0});       // red = 0
        for(auto edge : blueEdges)  graph[edge[0]].push_back({edge[1], 1});      // blue = 1

        bfs(graph, res);
    
        for(auto& d : res)  if(d == INT_MAX)  d = -1;

        return res;
    }
};