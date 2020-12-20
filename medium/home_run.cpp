/*
  Home Run
  Question 118 of 909
  
  https://binarysearch.com/problems/Home-Run
*/

int solve(int n) {
    int mx = 0;
    int cnt = 0;
    while (n) {
        while(n && n & 1) {
            cnt++;
            mx = max(mx, cnt);
            n >>= 1;
        }
        cnt = 0;
        while (n && (n & 1) == 0)
            n >>= 1;
    }
    return mx;
}
