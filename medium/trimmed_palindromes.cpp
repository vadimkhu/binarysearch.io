#define _MY_DEBUG
#ifdef _MY_DEBUG
#include <fstream>
#endif

/*
  Trimmed Palindromes
  https://binarysearch.com/problems/Trimmed-Palindromes
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solve(string s) {   
    int n = s.length();
    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(n));

    for (int gap = 0; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++,j++) {
            if (gap == 0) 
                dp[i][j] = 1;
            else if (gap == 1) 
                dp[i][j] = (s[i] == s[j]) ? 1 : 0;
            else if(s[i]==s[j] && dp[i+1][j-1] == 1) 
                dp[i][j]= true;

            ans += dp[i][j];
        }
    }        
    return ans;    
}

int main() {
#ifdef _MY_DEBUG
  ifstream fin("trimmed_palindrome_in.txt");
  cin.rdbuf(fin.rdbuf());
#endif

  string s;
  cin >> s;
  
  cout << solve(s) << endl;
  
  return 0;
}
