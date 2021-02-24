/*
    Dominos
    Question 372 of 1004
    
    https://binarysearch.com/problems/Dominos
*/

int solve(int n) {
    int mod = 1e9 + 7;
    if (n & 1) return 0;
    long long a[4] = {};
    a[0]=1;
    a[1]=0;
    a[2]=3;
    a[3]=0;
    for (int i = 4; i <= n; i++) 
        a[i%4] = (a[(i-2)%4] * 4 - a[i%4] + mod) % mod;
    return a[n%4];
}
