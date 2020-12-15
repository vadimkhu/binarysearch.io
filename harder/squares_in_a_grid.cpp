#ifdef _MY_DEBUG
#include <fstream>
#endif

/*
  Squares in a Grid
  https://binarysearch.com/problems/Squares-in-a-Grid
*/

#include <iostream>

using namespace std;

int calc(int64_t r, int64_t c) {
    int64_t mod = 1000000007;
    int64_t res = 0;
    int64_t i = 1;
    int64_t lim = min(r, c);
    while (i != lim) {
        res += ((((r - i) * (c - i)) % mod) * i) % mod;
        res = res % mod;
        i++;
    }
    return res;
}

int solve(int r, int c) {
    int res = calc(r, c);
    return res;
}

int main() {
#ifdef _MY_DEBUG
  ifstream fin("squares_in_a_grid_in.txt");
  cin.rdbuf(fin.rdbuf());
#endif

  int r = 0, c = 0;
  cin >> r >> c;
  
  cout << solve(r, c) << endl;
  
  return 0;
}
