/*
  Anagram Difference
  Question 453 of 953

  https://binarysearch.com/problems/Anagram-Difference
*/

int count(string s0, string s1, int i) {
    if (i >= s0.length()) return 0;
    if (s0[i] == s1[i]) return count(s0, s1, i+1);
    string::value_type c = s1[i];
    vector<int> candidates;
    for (int j = i; j < s0.length(); j++)
        if (s0[j] == c) candidates.push_back(j);
    int swaps = 1e9;
    for (auto j : candidates) {
        string tmp(s0);
        swap(tmp[i], tmp[j]);
        swaps = min(swaps, count(tmp, s1, i+1) + 1);
    }
    return swaps;    
    
}
int solve(string s0, string s1) {
    return count(s0, s1, 0);
}
