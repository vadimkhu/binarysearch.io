/*
  Multiple Parentheses
  Question 403 of 953

  https://binarysearch.com/problems/Multiple-Parentheses
*/

int solve(string s) {
    int res = 0;
    int len = s.length();
    vector<int> longest(len);
    
    for (int i = 1; i < len; i++) {
        if (s[i] == ')' && 
            i - longest[i - 1] - 1 >= 0 && 
            s[i - longest[i - 1] - 1] == '(') {
            longest[i] = longest[i - 1] + 2 + 
                        ((i - longest[i - 1] - 2 >= 0) ? longest[i - longest[i - 1] - 2] : 0);
            res = max(res, longest[i]);
        }
    }
    return res;
}
