#define _MY_DEBUG
#ifdef _MY_DEBUG
#include <fstream>
#endif

/*
  Buy and Sell K Stocks
  Question 56 of 907
  https://binarysearch.com/problems/Buy-and-Sell-K-Stocks
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solve(vector<int>& prices, int k) {
    int n = prices.size();
    if (n <= 0 || k <= 0) return 0;

    if (2 * k > n) {
       int res = 0;
       for (int i = 1; i < n; i++) 
            res += max(0, prices[i] - prices[i - 1]);
        return res;
    }

    const int inf = 1e9;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j][0] = -inf;
            dp[i][j][1] = -inf;
        }
    }
    
    dp[0][0][0] = 0;
    dp[0][1][1] = -prices[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
            if (j > 0) {
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }
    }
    
    int res = 0;
    for (int j = 0; j <= k; j++) {
        res = max(res, dp[n - 1][j][0]);
    }

    return res;    
}
int main() {
#ifdef _MY_DEBUG
  ifstream fin("buy_and_sell_k_stocks_in.txt");
  cin.rdbuf(fin.rdbuf());
#endif

  int n;
  cin >> n;
  vector<int> prices(n);
  for (auto &p : prices) 
    cin >> p;
  int k;
  cin >> k;
  
  cout << solve(prices, k) << endl;
  
  return 0;
}
