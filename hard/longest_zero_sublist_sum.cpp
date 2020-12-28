/*
  Longest Zero Sublist Sum
  Question 116 of 953

  https://binarysearch.com/problems/Longest-Zero-Sublist-Sum
*/

#include "solution.hpp"
using namespace std;

int solve(vector<int>& nums) {
    int n = nums.size();
    int res = 0;
    unordered_map<int, int> length; // sum->i-j+1
    vector<int> prefix(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        
        if (sum == 0) 
            res = i + 1;         
        
        if (length.find(sum) != length.end())
            res = max(res, i - length[sum]);
        else
            length[sum] = i;
    }
    
    return res;
}
