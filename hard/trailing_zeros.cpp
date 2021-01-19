/*
  Trailing Zeros
  Question 396
  
  https://binarysearch.com/problems/Trailing-Zeros
*/

int count_2(int k) {
    int res = 0;
    while (k) {
        res++;
        k >>= 1;
    }
    return res;
}

int count_5(int k) {
    int res = 0;
    while (k >= 5) {
        res++;
        k /= 5;
    }
    return res;
}

int solve(int k) {
    return min(count_2(k), count_5(k));    
}
