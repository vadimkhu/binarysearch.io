#define _MY_DEBUG
#ifdef _MY_DEBUG
#include <fstream>
#endif

/*
  Unique Subsequences Equal to Target
  Question 102 of 907
  
  https://binarysearch.com/problems/Unique-Subsequences-Equal-to-Target
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solve(string s, string t) {
    int n = s.size();
    int m = t.size();
    int mod = 1e9 + 7;
    
    if (n == 0 || m == 0) return 0;
    
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for (int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if (i == 0) 
                dp[i][j] = 1;
            else if (j == 0) 
                dp[i][j] = 0;
            else {
                if (s[j-1] == t[i-1]) 
                    dp[i][j] = (dp[i-1][j-1] + dp[i][j-1]) % mod;
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[m][n];    
}

int main() {
#ifdef _MY_DEBUG
  ifstream fin("the_accountant_in.txt");
  cin.rdbuf(fin.rdbuf());
#endif

  string s, t;
  cin >> s >> t;
  
  cout << solve(s, t) << endl;
  
  return 0;
}
