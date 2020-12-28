/*
  Cycle Detection in a Matrix
  Question 838 of 953

  https://binarysearch.com/problems/Cycle-Detection-in-a-Matrix/submissions
*/

void id2coord(int i, int w, int &r, int &c) {
    r = i / w;
    c = i % w;
}

int coord2id(int w, int r, int c) {
    return r * w + c;
}

bool solve(vector<vector<int>>& matrix) {
   int n = matrix.size();
   if (n == 0) return false;
   int m = matrix[0].size();
   if (n == 1 || m == 1) return false;
   int size = n * m;
   
   int dr[] = {0, 1, 0, -1};
   int dc[] = {1, 0, -1, 0};
   
   vector<int> visited(size);
   vector<int> parent(size, -1);
   for (int r = 0; r < n; r++) {
       for (int c = 0; c < m; c++) {
           if (visited[coord2id(m, r, c)]) continue;
           queue<pair<int, int>> q;
           
           q.push({ r, c });
           visited[coord2id(m, r, c)] = 1;
           parent[coord2id(m, r, c)] = -1;
           
           while (!q.empty()) {
               pair<int, int> u = q.front();
               q.pop();
               
               int ur = u.first, uc = u.second, uid = coord2id(m, ur, uc);
               for (int i = 0; i < 4; i++) {
                   int vr = u.first + dr[i];
                   int vc = u.second + dc[i];
                   int vid = coord2id(m, vr, vc);
                   if (vr < 0 || vc < 0 || vr >= n || vc >= m) continue;
                   if (matrix[ur][uc] != matrix[vr][vc]) continue;
                   if (visited[vid]) {
                       if (parent[uid] != vid) {
                           return true;
                       }
                       continue;
                   }
                   
                   visited[vid] = 1;
                   parent[vid] = uid;
                   q.push({vr, vc});
               }
           }
       }
   }
   return false;
}
