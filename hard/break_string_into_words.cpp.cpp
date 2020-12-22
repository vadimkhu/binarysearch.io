/*
  Break String Into Words
  Question 85 of 913

  https://leetcode.com/problems/word-break/
*/

bool walk(string s, int index, vector<string> &words, vector<int> &visited) {
    if (index >= s.length()) return true;
    if (visited[index]) return false;
    
    for (string w : words) {
        if (s.find(w, index) == index) {
            if (walk(s, index + w.length(), words, visited)) return true;
        }
    }
        
    visited[index] = true;
    return false;
}

bool solve(vector<string>& words, string s) {
    vector<int> visited(s.length());
    return walk(s, 0, words, visited);
}
