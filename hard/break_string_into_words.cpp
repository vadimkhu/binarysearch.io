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
#include <vector>
#include <algorithm>

using namespace std;

bool walk(string s, int index, vector<string> &words, vector<int> &visited) {
    if (index >= s.length()) return true;
    if (visited[index]) return false;
    
    for (string w : words) {
        if (s.find(w, index) == index) {
            if (walk(s, index + w.length(), words, visited)) return true;
        }
    }
        
    visited[index] = true;
    return false;
}

bool solve(vector<string>& words, string s) {
    vector<int> visited(s.length());
    return walk(s, 0, words, visited);
}

int main() {
#ifdef _MY_DEBUG
  ifstream fin("break_string_into_words.txt");
  cin.rdbuf(fin.rdbuf());
#endif

  int n;
  cin >> n;
  vector<string> words(n);
  for (auto &w : words) 
    cin >> w;
  string s;
  cin >> s;
  
  cout << solve(words, s) << endl;
  
  return 0;
}
