#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int depth = 0;

        for (char c : s) {
            if (c == '(') {
                if (depth > 0) {
                    result += c;
                }
                depth++;
            }
            else {
                depth--;
                if (depth > 0) {
                    result += c;
                }
            }
        }

        return result;
    }
};

int main() {
    string s;
    cout << "Enter a valid parentheses string: ";
    cin >> s;

    Solution sol;
    string result = sol.removeOuterParentheses(s);

    cout << "The string after removing the outermost parentheses is: " << result <<endl;

    return 0;
}
