/*
  Longest Arithmetic Subsequence
  Question 39 of 1000

  https://binarysearch.com/problems/Longest-Arithmetic-Subsequence
*/

int solve(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    
    vector<vector<int>> dp(n, vector<int>(10001));

    int ans = 0; 
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            int d = nums[i] - nums[j] + 5000;
            dp[i][d] = max(dp[i][d], dp[j][d]+1); 
            ans = max(dp[i][d], ans); 
        }
    }
    return ans+1; 
}
