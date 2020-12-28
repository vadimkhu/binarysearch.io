/*
  Create Largest Number From a List
  Question 54 of 953

  https://binarysearch.com/problems/Create-Largest-Number-From-a-List
*/

#include "solution.hpp"
using namespace std;

int to_int(string s) {
    int res = 0;
    for (int i = 0; i < s.length(); i++) res = res * 10 + (s[i] + '0');
    return res;
}

bool compare(string a, string b) {
    int len = min(a.length(), b.length());
    int tail = max(a.length(), b.length()) - len;
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) return a[i] > b[i];
    }
    return to_int(a + b) > to_int(b + a);
}

class Solution {
    vector<string> to_strings_vector(const vector<int>& nums) {
        vector<string> res;
        for (int i = 0; i < nums.size(); i++) {
            stringstream ss;
            ss << nums[i];
            res.push_back(ss.str());
        }
        return res;
    }

    public:
    string solve(vector<int>& nums) {
        vector<string> strs = to_strings_vector(nums);
        sort(strs.begin(), strs.end(), compare);
        copy(strs.begin(), strs.end(), ostream_iterator<string>(cout, " "));

        string res;
        for (int i = 0; i < strs.size(); i++) res += strs[i];
        return res;
    }
};

string solve(vector<int>& nums) {
    return (new Solution())->solve(nums);
}
