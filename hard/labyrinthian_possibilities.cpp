#define _MY_DEBUG
#ifdef _MY_DEBUG
#include <fstream>
#endif

/*
  Labyrinthian Possibilities
  Question 15 of 907
  https://binarysearch.com/problems/Labyrinthian-Possibilities
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return 0;
    int m = matrix[0].size();
    if (m == 0) return 0;
    if (matrix[0][0] == 1 || matrix[n-1][m-1] == 1) return 0;
    
    int mod = 1e9 + 7;
    int ans = 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for (int i = 0; i <= n; ++i)
        dp[i][0] = -1;
    for (int j = 0; j <= m; ++j)
        dp[0][j] = -1;
    dp[1][1] = 1; 
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (matrix[i-1][j-1] == 1) {
                dp[i][j] = -1;
                continue;
            }
            if (dp[i-1][j] != -1) dp[i][j] += dp[i-1][j];
            if (dp[i][j-1] != -1) dp[i][j] += dp[i][j-1];
        }
    }
    return dp[n][m];
}

int main() {
#ifdef _MY_DEBUG
  ifstream fin("labyrinthian_possibilities_in.txt");
  cin.rdbuf(fin.rdbuf());
#endif

  int n;
  cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  cout << solve(matrix) << endl;
  
  return 0;
}
