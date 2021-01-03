//#define _MY_DEBUG
#ifdef  _MY_DEBUG
#include <fstream>
#endif

/*
    Foo Bar Qaz Qux
    Question 171 of 991

    https://binarysearch.com/problems/Foo-Bar-Qaz-Qux
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solve(vector<string>& quxes) {
    int r = 0, g = 0, b = 0;
    for (auto c : quxes) {
        if (c == "R") r++;
        else if (c == "G") g++;
        else if (c == "B") b++;
    }
    /*
        if Quxes are all of the same color, the result is the size of Quxes;
        if the parities of each color are equal, the result is 2;
        if the parities of each color are mixed, the result is 1.
    */
    if (r == quxes.size() || g == quxes.size() || b == quxes.size()) {
        return quxes.size();
    }
    if ((r & 1) == (g & 1) && (r & 1) == (b& 1)) {
        return 2;
    }
    return 1;
}

int main() {
#ifdef _MY_DEBUG
    ifstream fin("input.txt");
    cin.rdbuf(fin.rdbuf());
#endif
    vector<string> qux = { "R","G","B","G","B" };
    cout << solve(qux) << endl;

	return 0;
}
