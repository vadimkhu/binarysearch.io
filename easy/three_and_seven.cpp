/*
  3 and 7
  Question 285 of 909

  https://binarysearch.com/problems/3-and-7
*/

bool solve(int n) {
    while (n >= 0) {
        if (n % 7 == 0) return true;
        if (n % 3 == 0) return true;
        if (n >= 7) n -= 7;
        else if (n >= 3) n -= 3;
        else break;
    }
    return n == 0;
}
