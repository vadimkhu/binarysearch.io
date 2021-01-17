/*
  Rotation of Another String
  Question 30 of 1006
  
  https://binarysearch.com/problems/Rotation-of-Another-String
*/

bool solve(string s0, string s1) {
    int n = s0.length();
    if (n != s1.length()) return false;
    int i = 0;
    int j = 0;
    while (i < n && j < n) {
        while (i < n && !(s0[i] == s1[0] && s0[(i+1)%n] == s1[1])) i++;
        int k = i;
        for (j = 0; j < n && s0[k%n] == s1[j]; j++, k++);
        i++;
    }
    return j == n;
}
