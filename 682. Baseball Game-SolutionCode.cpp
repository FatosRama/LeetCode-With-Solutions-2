#include <iostream>
#include <vector>
#include <string>

using namespace std;

int calPoints(vector<string>& ops) {
    vector<int> record;

    for (const string& op : ops) {
        if (op == "C") {
            if (!record.empty()) {
                record.pop_back();
            }
        }
        else if (op == "D") {
            if (!record.empty()) {
                record.push_back(2 * record.back());
            }
        }
        else if (op == "+") {
            if (record.size() >= 2) {
                record.push_back(record[record.size() - 1] + record[record.size() - 2]);
            }
        }
        else {
            record.push_back(stoi(op));
        }
    }

    int sum = 0;
    for (int score : record) {
        sum += score;
    }

    return sum;
}

int main() {
    int n;
    cout << "Enter the number of operations: ";
    cin >> n;

    vector<string> ops(n);
    
    for (int i = 0; i < n; ++i) {
        cout << "Enter the "<<i+1<< " operation: ";
        cin >> ops[i];
    }

    int result = calPoints(ops);
    cout << "The final score is: " << result << endl;

    return 0;
}
