/*
  Dictionary Nomad
  Question 274 of 1000

  https://binarysearch.com/problems/Dictionary-Nomad
*/

int solve(vector<string>& dictionary, string start, string end) {
    int L = start.length();
    unordered_map<string, vector<string>> allCombo;

    for (auto word : dictionary) {
        for (int i = 0; i < L; i++) {
            string new_word = word.substr(0, i) + '*' + word.substr(i + 1, L - i - 1);
             allCombo[new_word].push_back(word);
        }
    }
    queue<pair<string, int>> q;
    unordered_map<string, bool> seen;
    q.push({start, 1});
    seen[start] = true;

    while (!q.empty()) {
        pair<string, int> node = q.front();
        q.pop();
        string word = node.first;
        int level = node.second;
        for (int i = 0; i < L; i++) {
            string nword = word.substr(0, i) + '*' + word.substr(i + 1, L - i - 1);
            for (string adjword : allCombo[nword]) {
                if (adjword == end) return level + 1;
                if (!seen[adjword]) {
                    seen[adjword] = true;
                    q.push({adjword, level + 1});
                }
            }
        }
    }

    return -1;
}
