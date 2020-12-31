/*
  String Expansion
  Question 151 of 977

  https://binarysearch.com/problems/String-Expansion
*/

bool is_digit(string::value_type c) {
    return c >= '0' && c <= '9';
}

bool is_letter(string::value_type c) {
    return c >= 'a' && c <= 'z';
}

string parse(string s, int &index, int state) { 
    string ret;
    int num = 0;
    string sub;

    while (index < s.length() && state != 15) {
        switch (state) {
            case 0:
                if (is_digit(s[index]))
                    state = 1;
                else 
                    state = 15;
                break;
            case 1:
                if (is_digit(s[index])) 
                    num = num * 10 + (s[index]-'0');
                else if (s[index] == '(') 
                    state = 2;
                else 
                    state = 15;
                index++;
                break;
            case 2:
                if (is_letter(s[index])) {
                    sub.push_back(s[index]);
                    index++;
                }
                else if (is_digit(s[index])) 
                    sub += parse(s, index, 1);
                else if (s[index] == ')') {
                    state = 0;
                    for (int i = 0; i < num; i++) 
                        ret += sub;
                    sub = "";
                    num = 0;
                    index++;
                }
                else 
                    state = 15;
                break;
            default:
                state = 15;
                break;
        }
    }
    return ret;
}

string solve(string s) {
    int index = 0;
    return parse(s, index, 0);    
}
