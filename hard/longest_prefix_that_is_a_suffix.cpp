/*
  Longest Prefix that Is a Suffix
  Question 718 of 953

  https://binarysearch.com/problems/Longest-Prefix-that-Is-a-Suffix
*/

string solve(string s) {
    int n = s.length();
    int lps[n];
    lps[0] = 0; // lps[0] is always 0

    int len = 0;
    int i = 1;
    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
 
    return s.substr(0, lps[n-1]);
}
