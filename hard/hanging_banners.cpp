/*
  Hanging Banners
  Question 208 of 1000
  
  https://binarysearch.com/problems/Hanging-Banners
*/

int solve(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if (n == 0) return 0;
    sort(intervals.begin(), intervals.end(), 
        [](const vector<int>& l, const vector<int>& r) {
            return l[1] < r[1];
    });

    int l = intervals[0][1];
    int ans = 1;

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] > l) {
            ans++;
            l = max(l, intervals[i][1]);
        }
    }
    return ans;
}
