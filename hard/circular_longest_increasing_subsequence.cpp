/*
  Circular Longest Increasing Subsequence
  Question 530 of 953

  https://binarysearch.com/problems/Circular-Longest-Increasing-Subsequence
*/

int longest(vector<int> &nums, int i, int j) {
    vector<int> dp;
    for (int k = i; k < j; k++) {
        int x = nums[k];
        int id = 0;
        while (id < dp.size() && dp[id] < x) id++;
        if (id >= dp.size())
            dp.push_back(x);
        else
            dp[id] = x;
    }
    return dp.size();
}

int solve(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.end(), nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < n; i++) 
        ans = max(ans, longest(nums, i, i + n));
    return ans;
}
