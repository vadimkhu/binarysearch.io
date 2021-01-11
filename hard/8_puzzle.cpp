/*
  8-Puzzle
  Question 304 of 1001
  
  https://binarysearch.com/problems/8-Puzzle
*/

int solve(vector<vector<int>>& board) {
    string start = "";
    string target = "012345678";
    int row = 3, column = 3;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            start.push_back(board[i][j] + '0');
        }
    }
    vector<vector<int>> neighbour {{1,3}, {0,2,4,}, {1,5}, {0,4,6}, {1,3,5,7}, {2,4,8}, {3,7}, {4,6,8}, {5,7}};
    queue<string> q;
    unordered_set<string> visited;
    q.push(start);
    int step = 0;
    while(!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            string curr = q.front();
            q.pop();
            if (curr == target) return step;
            int index = 0;
            for (; curr[index] != '0'; index++);
            for (int adj : neighbour[index]) {
                string new_board = curr;
                swap(new_board[adj], new_board[index]);
                if (!visited.count(new_board)) {
                    q.push(new_board);
                    visited.insert(new_board);
                }
            }
        }
        step++;
    }
    return -1;
}
