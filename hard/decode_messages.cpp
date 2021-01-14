int solve(string s) {
    size_t n = s.size();
    const int mod = 1e9 + 7;

    if (n == 0) return 0;
    if (n < 2) return s[0] == '0' ? 0 : (s[0] == '*' ? 9 : 1);
    long long dp2 = 1, dp1 = s[0] == '0' ? 0 : (s[0] == '*' ? 9 : 1), dp = 0;
    for (size_t i = 2; i <= n; ++i) {
        dp = s[i-1] == '0' ? 0 : (s[i-1] == '*' ? 9 * dp1 : dp1);
        dp = (dp % mod) % mod;
        if (s[i-2] == '1' && s[i-1] == '*') dp += dp2 * 9;
        else if (s[i-2] == '2' && s[i-1] == '*') dp += dp2 * 6;
        else if (s[i-2] == '*' && s[i-1] == '*') dp += dp2 * 15;
        else if (s[i-2] == '*' && s[i-1] <= '6') dp += dp2 * 2;
        else if (s[i-2] == '*' && s[i-1] >= '7') dp += dp2;
        else if ((s[i-2] =='1' && s[i-1] != '*') || (s[i-2] =='2' && s[i-1] <= '6')) dp += dp2;
        dp = (dp % mod) % mod;
        dp2 = dp1;
        dp1 = dp;
    }
    return dp;
}
