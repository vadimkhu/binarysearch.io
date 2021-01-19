/*
  Equivalent Pairs
  Question 964
  
  https://binarysearch.com/problems/Equivalent-Pairs
*/

int solve(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> h;
    int res = 0;
    for (int i = 0; i < n; i++) 
        res += h[nums[i]]++;
    return res;
}
