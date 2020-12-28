/*
  Sinking Islands
  Question 49 of 953
  
  https://binarysearch.com/problems/Sinking-Islands
*/  

void bfs(int row, int col, vector<vector<int>> &board, vector<vector<int>> &land) {
    size_t h = board.size();
    if (h == 0) return;
    size_t w = board[0].size(); 
    queue<pair<int, int>> q;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    
    q.push({row, col});
    land[row][col] = 1;
    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int vr = u.first + dr[i];
            int vc = u.second + dc[i];
            if (vr < 0 || vr >= h || vc < 0 || vc >= w || board[vr][vc] == 0 || land[vr][vc]) continue;
            land[vr][vc] = 1;
            q.push({vr, vc});
        }
    }
    
}
vector<vector<int>> solve(vector<vector<int>>& board) {
    size_t h = board.size();
    if (h == 0) return board;
    size_t w = board[0].size(); 
    vector<vector<int>> land(h, vector<int>(w));

    for (int c = 0; c < w; c++) {
        if (board[0][c] == 0 || land[0][c]) continue;
        bfs(0, c, board, land);
    }
    for (int c = 0; c < w; c++) {
        if (board[h-1][c] == 0 || land[h-1][c]) continue;
        bfs(h-1, c, board, land);
    }
    for (int r = 1; r < h-1; r++) {
        if (board[r][0] == 0 || land[r][0]) continue;
        bfs(r, 0, board, land);
    }
    for (int r = 1; r < h-1; r++) {
        if (board[r][w-1] == 0 || land[r][w-1]) continue;
        bfs(r, w-1, board, land);
    }
    return land;
}
