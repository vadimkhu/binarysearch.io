/*
  Longest Anagram Subsequence
  Question 69 of 927
  
  https://binarysearch.com/problems/Longest-Anagram-Subsequence
*/

int solve(string a, string b) {
    const int SIZE = 26;
    int n = a.length();
    int m = b.length(); 
    
    vector<int> f1(SIZE);
    vector<int> f2(SIZE);

    int len = 0; 
    for (int i = 0; i < n; i++) 
        f1[a[i] - 'a']++; 
    for (int i = 0; i < m; i++)     
        f2[b[i] - 'a']++; 
      
    for (int i = 0; i < SIZE; i++)     
        len += min(f1[i], f2[i]); 
    return len;     
}
