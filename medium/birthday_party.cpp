/*
  Birthday Party
  Question 159 of 1002
  
  https://binarysearch.com/problems/Birthday-Party
*/

int joseph (int n, int k) {
	int res = 0;
	for (int i = 1; i <= n; ++i)
		res = (res + k) % i;
	return res + 1;
}

int solve(int n, int k) {
    return joseph(n, k+1)-1;    
}
