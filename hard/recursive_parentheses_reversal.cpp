/*
  Recursive Parentheses Reversal
  Question 694 of 953

  https://binarysearch.com/problems/Recursive-Parentheses-Reversal
*/

string solve(string s) {
    stack<int> rangeIndices;
	vector<int> rangeEnds; 
	
	int letters = 0; 
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(') {
			rangeIndices.push(rangeEnds.size());
			rangeEnds.push_back(0);
		} 
		else if (s[i] == ')') {
			rangeEnds[rangeIndices.top()] = letters;
			rangeIndices.pop();
		} 
		else {
			++letters;
		}
	}

	string result(letters, '-');
	stack<pair<int, int>> mappings; 
	
	mappings.push({1, 0}); 
	int rangeIndex = 0;
	int letterIndex = 0;

	for (int i = 0; i < s.length(); ++i) {
		auto& [a, b] = mappings.top();

		if (s[i] == '(') {
			int c = -1;
			int d = rangeEnds[rangeIndex] - 1 + letterIndex;

			mappings.push({ a * c, a * d + b });
			++rangeIndex;
		} 
		else if (s[i] == ')') {
			mappings.pop();
		} 
		else {
			result[a * letterIndex + b] = s[i];
			++letterIndex;
		}
	}

	return result;
}
