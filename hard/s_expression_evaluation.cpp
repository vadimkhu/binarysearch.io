/*
  S-Expression Evaluation
  Question 155 of 953

  https://binarysearch.com/problems/S-Expression-Evaluation
*/

long evaluate(long a, long b, string op) {
    if (op == "+")
        return a + b;
    if (op == "-")
        return a - b;
    if (op == "*")
        return a * b;
    return a / b;
}

bool is_operation(string op) {
    return op == "+" || op == "-" || op == "*" || op == "/";
}

int solve(string str) {
    string s;
    for (auto c : str) {
        if (c == '(') {
            s += c;
            s += ' ';
        }
        else if (c == ')') {
            s += ' ';
            s += c;
        }
        else s += c;
    }
    vector<string> tokens;
    stringstream ss(s);
    string item;
    while (getline(ss, item, ' ')) {
        tokens.push_back(item);
    }

    stack<string> q;
    stack<long> res;
    for (auto t : tokens) {
        if (is_operation(t)) { 
            q.push(t);
        }
        else if (t != "(" && t != ")") {
            res.push(stoi(t));
        }
        else if (t == ")") {
            long b = res.top();
            res.pop();
            long a = res.top();
            res.pop();
            long c = evaluate(a, b, q.top());
            q.pop();
            res.push(c);
        }
    }
    return res.top();
}
