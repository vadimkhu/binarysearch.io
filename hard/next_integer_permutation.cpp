#define _MY_DEBUG
#ifdef _MY_DEBUG
#include <fstream>
#endif

/*
  Next Integer Permutation
  Question 101 of 907
  https://binarysearch.com/problems/Next-Integer-Permutation/
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

vector<int> to_array(int n) {
    vector<int> res;
    while (n) {
        res.insert(res.begin(), n % 10);
        n /= 10;
    }
    return res;
}

int to_number(vector<int> &arr) {
    int n = 0;
    for (int i = 0; i < arr.size(); i++) {
        n = n * 10 + arr[i];
    }
    return n;
}

int solve(int n) {
    vector<int> arr = to_array(n);
    next_permutation(arr.begin(), arr.end());
    return to_number(arr);
}

int main() {
#ifdef _MY_DEBUG
  ifstream fin("next_integer_permutation_in.txt");
  cin.rdbuf(fin.rdbuf());
#endif

  int n;
  cin >> n;
  
  cout << solve(n) << endl;
  
  return 0;
}
