/*
  Split String Into Palindromes
  Question 52 of 953

  https://binarysearch.com/problems/Split-String-Into-Palindromes
*/

#include "solution.hpp"

using namespace std;

class Solution {
    public:
    int solve(string s) {
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len));
        for (int i = 0; i < len; i++) dp[i][i] = 1;
        for (int i = 0; i < len - 1; i++) dp[i][i + 1] = s[i] == s[i + 1];

        int i = 0;
        int k = 3;
        while (k <= len) {
            while (i < (len - k + 1)) {
                int j = i + k - 1;
                dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                i++;
            }
            k++;
            i = 0;
        }
        vector<int> p(len + 1);
        for (i = 0; i < len + 1; i++) {
            for (int j = 0; j < i; j++) {
                int matrix_i = i - 1;
                if (dp[j][matrix_i])
                    if (p[i] == 0 || (p[j] + 1) < p[i]) p[i] = p[j] + 1;
            }
        }
        return p[len];
    }
};

int solve(string s) {
    return (new Solution())->solve(s);
}

