#define _MY_DEBUG
#ifdef  _MY_DEBUG
#include <fstream>
#endif

/*
  Longest Alternating Subsequence
  Question 348 of 909

  https://binarysearch.com/problems/Longest-Alternating-Subsequence
*/

#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<vector<int>> las(n, vector<int>(2, 1));
    int res = 1; 
  
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if (nums[j] < nums[i])
                las[i][0] = max(las[i][0], las[j][1] + 1);
            if (nums[j] > nums[i])
                las[i][1] = max(las[i][1], las[j][0] + 1);
        }
        res = max(res, max(las[i][0], las[i][1]));
    }
    return res;    
}

int main() { 
#ifdef _MY_DEBUG 
  ifstream fin("longest_alternating_subsequence.txt");
  cin.rdbuf(fin.rdbuf());
#endif
  int n = 0;
  cin >> n;
  vector<int> arr(n, 0);
  for (auto& e : arr)
    cin >> e;
    
  cout << solve(arr) << endl;
  
  return 0;
}
