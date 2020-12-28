/*
  Largest Rectangle Submatrix
  Question 45 of 953

  https://binarysearch.com/problems/Largest-Rectangle-Submatrix
*/

#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        vector<int> dp(matrix[0].size(), 0);
        int res = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < dp.size(); j++) {
                if (matrix[i][j] == 1) {
                    dp[j]++;
                    int t = j - 1, len = 2, m = dp[j];
                    res = max(res, m);
                    while (t >= 0) {
                        if (dp[t] == 0) break;
                        m = min(m, dp[t]);
                        res = max(res, m * len);
                        len++;
                        t--;
                    }
                } else
                    dp[j] = 0;
            }
        }
        return res;
    }
};

int solve(vector<vector<int>>& matrix) {
    return (new Solution())->solve(matrix);
}
