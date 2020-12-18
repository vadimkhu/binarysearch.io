/*
  Painting Houses
  Question 13 of 906
  
  https://binarysearch.com/problems/Painting-Houses
*/

int solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return 0;
    int k = matrix[0].size();
    if (k == 0) return 0;
        
    vector<vector<int>> costs(matrix);
    int res = INT_MAX;

    int preMin = 0;
    int preSecond = 0;
    int preIndex = -1; 
 
    for(int i = 0; i < n; i++) {
        int currMin = INT_MAX;
        int currSecond = INT_MAX;
        int currIndex = 0;
 
        for (int j = 0; j < k; j++) {
            if (preIndex == j) {
                costs[i][j] += preSecond;
            } 
            else {
                costs[i][j] += preMin;
            }
 
            if (currMin > costs[i][j]) {
                currSecond = currMin;
                currMin = costs[i][j];
                currIndex = j;
            } 
            else if (currSecond > costs[i][j]) {
                currSecond = costs[i][j];
            }
        }
        preMin = currMin;
        preSecond = currSecond;
        preIndex = currIndex;
    }

    for (int j = 0; j < k; j++) {
        res = min(res, costs[n-1][j]);
    }    
    return res;
    
}
