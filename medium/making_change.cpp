/*
  Making Change
  Question 76 of 1000
  
  https://binarysearch.com/problems/Making-Change
*/

int solve(int n) {
    int coins[] = {1, 5, 10, 25};
    int i = 3;
    int ans = 0;
    while (n) {
        if (n >= coins[i]) {
            ans += n / coins[i];
            n %= coins[i];
        } 
        else i--;
    }
    return ans;
}
