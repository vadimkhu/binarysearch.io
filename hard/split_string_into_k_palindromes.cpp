/*
  Split String Into K Palindromes
  Question 808 of 953

  https://binarysearch.com/problems/Split-String-Into-K-Palindromes
*/

#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(string s, int k) {
        const int INF = 10000;

        int n = s.size();
        vector<vector<int>> subs(n, vector<int>(n, 0));
        vector<vector<int>> dp(k + 1, vector<int>(n, INF));

        for (int i = 0; i < n; i++) subs[i][i] = 0;
        for (int i = 0; i < n - 1; i++) subs[i][i + 1] = (s.substr(i, 1) != s.substr(i + 1, 1));
        for (int l = 2; l < n; l++) {
            for (int i = 0; i < n - l; i++) {
                int j = i + l;
                subs[i][j] = subs[i + 1][j - 1] + (s.substr(i, 1) != s.substr(j, 1));
            }
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = 0;
            dp[1][j] = subs[0][j];
        }
        for (int i = 2; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                int min_s = INF;
                for (int l = 0; l < j; l++) {
                    min_s = min(min_s, dp[i - 1][l] + subs[l + 1][j]);
                }
                dp[i][j] = min_s;
            }
        }
        return dp[k][n - 1];
    }
};

int solve(string s, int k) {
    return (new Solution())->solve(s, k);
}
