/*
  Trailing Zeros
  Question 396
  
  https://binarysearch.com/problems/Trailing-Zeros
*/

int log_5(int k) {
    int res = 0;
    while (k >= 5) {
        res++;
        k /= 5;
    }
    return res;
}

int solve(int k) {
    return log_5(k);
}
