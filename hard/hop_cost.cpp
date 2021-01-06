/*
  Hop Cost
  Question 606 of 1000

  https://binarysearch.com/problems/Hop-Cost
*/

int solve(vector<int>& nums0, vector<int>& nums1, int dist, int cost) {
    int n = nums0.size();
    const int inf = INT_MAX;
    vector<vector<int>> dp(2, vector<int>(n, inf));
    dp[0][0] = min(nums0[0], nums1[0] + cost);
    dp[1][0] = min(nums1[0], nums0[0] + cost);
    for (int i = 0; i < n; i++) {
        int j = i + 1;
        for (; j < n && j - i - 1 < dist; j++) {
            dp[0][j] = min(dp[0][j], min(dp[0][i] + nums0[j], dp[1][i] + nums1[j] + cost));
            dp[1][j] = min(dp[1][j], min(dp[1][i] + nums1[j], dp[0][i] + nums0[j] + cost));
        }
    }
    return min(dp[0][n - 1], dp[1][n - 1]);
}
