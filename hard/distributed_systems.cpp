/*
    Distributed Systems
    Question 214 of 1004
    
    https://binarysearch.com/problems/Distributed-Systems
*/

int dijkstra(vector<vector<pair<int, int>>> &g, int n, int s) {
    const int INF = 1000000000;
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
    pq.push({0, s});
	dist[s] = 0;
    int ans = 0;
    while (!pq.empty()) {
        int from = pq.top().second; 
        pq.pop(); 
		for (size_t i = 0; i < g[from].size(); ++i) {
			int to = g[from][i].first;
			int time = g[from][i].second;
			if (dist[from] + time < dist[to]) {
				dist[to] = dist[from] + time;
				pq.push({dist[to], to});
                ans = max(ans, dist[to]);
			}
		}
	}    
    return ans;    
}

int solve(int n, vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> g(n + 1);
    for (auto e : edges) {
        g[e[0]].push_back({e[1], e[2]});
        g[e[1]].push_back({e[0], e[2]});
    }
    
    return dijkstra(g, n, 0); 
}
