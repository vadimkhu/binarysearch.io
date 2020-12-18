/*
  Merge New Interval
  Question 113 of 905

  https://binarysearch.com/problems/Merge-New-Interval
*/

vector<vector<int>> solve(vector<vector<int>>& intervals, vector<int>& target) {
    vector<vector<int>> res;
    int l = target[0];
    int r = target[1];

    bool merged = false;

    for (auto interval : intervals) {
        if (interval[1] < target[0])
            res.push_back(interval);
        else if (interval[0] > r) {
            if (!merged) {
                res.push_back({l, r});
                merged = true;
            }
            res.push_back(interval);
        } 
        else {
            l = min(l, interval[0]);
            r = max(r, interval[1]);
        }
    }
    if (!merged) 
        res.push_back({l, r});

    return res;
}
