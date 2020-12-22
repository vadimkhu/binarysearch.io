/*
  Longest Common Subsequence of Three Strings
  Question 212 of 913

  https://binarysearch.com/problems/Longest-Common-Subsequence-of-Three-Strings/submissions/3058794
*/

int solve(string a, string b, string c) {
    int m = a.length();
    int n = b.length();
    int o = c.length();
    
    vector<vector<vector<int>>> L(m+1, vector<vector<int>>(n+1, vector<int>(o+1))); 
    for (int i = 0; i <= m; i++) { 
        for (int j = 0; j <= n; j++) { 
            for (int k = 0; k <= o; k++) { 
                if (i == 0 || j == 0||k==0) 
                    L[i][j][k] = 0; 
                else if (a[i-1] == b[j-1] && a[i-1] == c[k-1]) 
                    L[i][j][k] = L[i-1][j-1][k-1] + 1; 
                else
                    L[i][j][k] = max(max(L[i-1][j][k], 
                                         L[i][j-1][k]), 
                                         L[i][j][k-1]); 
            } 
        } 
    } 
    return L[m][n][o];     
}
