/*
  Compress String
  Question 29 of 1000

  https://binarysearch.com/problems/Compress-String
*/

string solve(string s) {
    string res;
    size_t L = s.length();
    for (int i = 0; i < L;) {
        res += s[i];
        int j = i + 1;
        for (;j < L && s[i] == s[j]; j++);
        i = j;
    }
    return res;
}
