#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

string findDestinationCity(vector<vector<string>>& paths) {
    unordered_map<string, int> g;
    for (vector<string>& path : paths)
        g[path[0]] ++, g[path[1]];

    for (const pair<string, int>& p : g)
        if (p.second == 0) return p.first;
    return "";
}

int main() {
    vector<vector<string>> paths;
    string input, cityA, cityB;

    cout << "Enter paths (each path as 'CityA CityB' on a new line, end input with -1):" << endl;
    while (true) {
        getline(cin, input);
        if (input=="-1") break;

        size_t spacePos = input.find(' ');
        if (spacePos != string::npos) {
            cityA = input.substr(0, spacePos);
            cityB = input.substr(spacePos + 1);
            paths.push_back({ cityA, cityB });
        }
        else {
            cout << "Invalid input format. Please enter in the format 'CityA CityB'." << endl;
        }
    }

    string destinationCity = findDestinationCity(paths);

    cout << "Destination city: " << destinationCity << endl;

    return 0;
}
