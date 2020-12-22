/*
  Longest Substring with Even Vowel Counts
  Question 745 of 913
  
  https://binarysearch.com/problems/Longest-Substring-with-Even-Vowel-Counts
*/
// Solution: 

int solve(string s) {
    unordered_map<int, int> indexes{{0, -1}};
    unordered_map<char, int> vowels{{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
    int answer = 0;
    int mask = 0;
        
    for (int i = 0; i < s.size(); ++i) {
        if (vowels.count(s[i])) 
            mask ^= (1 << vowels[s[i]]);
        if (!indexes.count(mask))
            indexes[mask] = i;
        answer = max(answer, i - indexes[mask]);
    }
        
    return answer;
}
