#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    int n = names.size();
    vector<pair<int, string>> people;

    
    for (int i = 0; i < n; ++i) {
        people.push_back({ heights[i], names[i] });
    }

    
    sort(people.begin(), people.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return b.first < a.first;
        });

    
    vector<string> sortedNames;
    for (const auto& person : people) {
        sortedNames.push_back(person.second);
    }

    return sortedNames;
}

int main() {
    vector<string> names;
    vector<int> heights;
    string input;
    int height;

    cout << "Enter names and heights (end input with -1):" << endl;
    while (true) {
        cout << "Enter name: ";
        cin>>input;
        if (input=="-1") break;
        names.push_back(input);

        cout << "Enter height: ";
        cin >> height;
        heights.push_back(height);

        cin.ignore();  
    }

    vector<string> sortedNames = sortPeople(names, heights);

    cout << "Names sorted by heights in descending order:" << endl;
    for (const string& name : sortedNames) {
        cout << name << endl;
    }

    return 0;
}
