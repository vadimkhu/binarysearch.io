/*
    Longest Interval
    Question 333 of 1017
    
    https://binarysearch.com/problems/Longest-Interval    
*/

int solve(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), 
        [](vector<int> &l, vector<int> &r) {
            return l[0] < r[0];
        });
    stack<vector<int>> q;
    int res = intervals[0][1] - intervals[0][0] + 1;
    q.push(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
        vector<int> top = q.top();
        if (top[1] < intervals[i][0]) {
            q.push(intervals[i]);
            res = max(res, intervals[i][1] - intervals[i][0] + 1);
        }
        else if (top[1] < intervals[i][1]) {
            top[1] = intervals[i][1];
            res = max(res, top[1] - top[0] + 1);
            q.pop();
            q.push(top);
        }
    }
    return res;
}
