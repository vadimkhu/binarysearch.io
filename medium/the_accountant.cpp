#define _MY_DEBUG
#ifdef _MY_DEBUG
#include <fstream>
#endif

/*
  The Accountant
  Question 60 of 909
  https://binarysearch.com/problems/The-Accountant/
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string solve(int n) {
    string res;
    
    while (n) {
        int id = (--n) % 26;
        n /= 26;
        res.push_back(id + 'A');
    }
    reverse(res.begin(), res.end());
    
    return res;
}

int main() {
#ifdef _MY_DEBUG
  ifstream fin("the_accountant_in.txt");
  cin.rdbuf(fin.rdbuf());
#endif

  int n;
  cin >> n;
  
  cout << solve(n) << endl;
  
  return 0;
}
