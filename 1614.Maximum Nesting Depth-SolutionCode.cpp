#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int opened = 0;

        for (const char c : s)
            if (c == '(')
                ans = max(ans, ++opened);
            else if (c == ')')
                --opened;

        return ans;
    }
};

int main() {
    string s;
    cout << "Enter a valid parentheses string: ";
    cin >> s;

    Solution sol;
    int depth = sol.maxDepth(s);

    cout << "The maximum nesting depth of the parentheses is: " << depth << endl;

    return 0;
}
