/*
  Sudoku Validator
  Question 124
  
  https://binarysearch.com/problems/Sudoku-Validator
*/

bool isValid(int s[]) {
    for (int i = 0; i < 9; i++)
        if (s[i] != 1) return false;
    return true;
}

bool isValidRow(vector<vector<int>> &grid, int row) {
    int s[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] < 1 || grid[row][i] > 9) return false;
        s[grid[row][i]-1]++;
    }
    return isValid(s);
}

bool isValidCol(vector<vector<int>> &grid, int col) {
    int s[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] < 1 || grid[i][col] > 9) return false;
        s[grid[i][col]-1]++;
    }
    return isValid(s);
}

bool isValidSquare(vector<vector<int>> &grid, int rs, int cs) {
    int s[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[(rs*3+i)%3][(cs*3+j)%3] < 1 || grid[(rs*3+i)%3][(cs*3+j)%3] > 9) return false;
            s[grid[(rs*3+i)%3][(cs*3+j)%3]-1]++;
        }
    }
    return isValid(s);
}

bool solve(vector<vector<int>>& matrix) {
    for (int i = 0; i < 9; i++) 
        if (!isValidRow(matrix, i)) return false;
    for (int i = 0; i < 9; i++)
        if (!isValidCol(matrix, i)) return false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) 
            if (!isValidSquare(matrix, i, j)) return false;
    }
    return true;
}
