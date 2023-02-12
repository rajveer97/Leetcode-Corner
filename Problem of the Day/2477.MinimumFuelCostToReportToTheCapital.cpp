class Solution {
public:
    vector<vector<int>> edges;
    vector<bool> visited;
    long long minTotalFuel = 0; 

    int count(int cur, int k) {
        int cnt = 1;

        visited[cur] = true;

        for(auto i : edges[cur]) {
            if(visited[i] != true) {
                cnt += count(i, k);
            }
        }

        if(cur != 0) {
            minTotalFuel += ((cnt + k - 1)/k);
        }

        return cnt;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        edges.resize(n+1);
        visited.resize(n+1);

        for(auto road : roads) {
            edges[road[0]].push_back(road[1]);
            edges[road[1]].push_back(road[0]);
        }

        count(0, seats);

        return minTotalFuel;
    }
};