/*
  Minimum Difference
  Question 281 of 1006
  
  https://binarysearch.com/problems/Minimum-Difference
*/

int solve(vector<int>& lst0, vector<int>& lst1) {
    int res = INT_MAX;
    int n = lst0.size();
    int m = lst1.size();
    sort(lst0.begin(), lst0.end());
    sort(lst1.begin(), lst1.end());

    for (int i = 0, j = 0; i < n && j < m;) {
        res = min(res, abs(lst0[i]-lst1[j]));
        if (lst0[i] > lst1[j]) j++;
        else i++;
    }
    
    return res;
}
