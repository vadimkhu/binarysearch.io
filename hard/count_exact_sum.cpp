/*
  Count Exact Sum
  Question 449 of 1005
  
  https://binarysearch.com/problems/Count-Exact-Sum
*/

int solve(vector<int>& nums, int k) {
    int n = nums.size();
    int mod = 1e9 + 7;
    vector<vector<long long>> dp(n+1, vector<long long>(k+1));

    for (int i = 0; i <= n; i++)  
         dp[i][0] = 1;
    for (int i = 1; i <= n; i++) { 
        for (int x = 1; x <= k; x++) { 
            if (x < nums[i-1]) 
                dp[i][x] = dp[i-1][x];
            else //if (x >= nums[i-1])
                dp[i][x] = (dp[i-1][x] + dp[i-1][x-nums[i-1]]) % mod;
        }
    }
    return dp[n][k];
}
