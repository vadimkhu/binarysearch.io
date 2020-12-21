/*
  Justify Text
  Question 242 of 909

  https://binarysearch.com/problems/Justify-Text
*/

vector<string> solve(vector<string>& words, int k) {
    vector<string> res;
    for (int i = 0; i < words.size();) {
        int start = i;
        int amount = k - words[i++].length();
        while (amount && words[i].length() + 1 <= amount) {
            amount -= words[i].length() + 1;
            i++;
        }
        int extra = amount;             // extra spaces
        int wc = i - start;             // words count
        int gc = wc > 1 ? wc - 1 : 1;   // gaps count
        vector<int> gaps(gc, wc > 1 ? 1 : 0);
        for (int j = gaps.size()-1; j >= 0; j--) {
            gaps[j] += extra / gc;
            extra -= extra / gc;
            gc -= 1;
        }
        string line;
        for (int j = start; j < i; j++) {
            line += words[j];
            // fill gaps with spaces
            for (int l = 0; j-start < gaps.size() && l < gaps[j-start]; l++)
                line += ' ';
        }
        res.push_back(line);
    }
    return res;
}
