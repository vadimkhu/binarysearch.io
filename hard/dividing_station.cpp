/*
  Dividing Station
  Question 212 of 1006
  
  https://binarysearch.com/problems/Dividing-Station
*/

int solve(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> dp(n, 1);
    int res = 1;

    sort(nums.begin(), nums.end());

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) { 
            if (nums[i] % nums[j] == 0) {
                dp[i] = max(dp[i], 1 + dp[j]);
                res = max(res, dp[i]);
            }
        }
    }
    return res;
}
