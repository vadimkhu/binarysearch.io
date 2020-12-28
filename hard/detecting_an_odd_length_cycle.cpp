/*
  Detecting an Odd Length Cycle
  Question 95 of 953

  https://binarysearch.com/problems/Detecting-an-Odd-Length-Cycle
*/

bool solve(vector<vector<int>>& arr) {
    int V = arr.size();
    vector<int> color(V, -1);
    int src = 0;
    color[src] = 1;
    
    queue <int> q; 
    q.push(src); 
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop(); 
   
        for (auto v : arr[u]) {
            if (v == u) 
                return true;
            if (color[v] == -1) { 
                color[v] = 1 - color[u]; 
                q.push(v); 
            } 
            else if (color[v] == color[u]) 
                return true; 
        } 
    }     
    return false;
}
