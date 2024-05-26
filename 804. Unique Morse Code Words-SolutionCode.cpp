#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> morse = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",
                            ".---","-.-",".-..","--","-.","---",".--.","--.-",
                            ".-.","...","-","..-","...-",".--","-..-","-.--","--.." };

    unordered_set<string> uniqueTransformations;

    for (const string& word : words) {
        string transformation;
        for (char c : word) {
            transformation += morse[c - 'a'];
        }
        uniqueTransformations.insert(transformation);
    }

    return uniqueTransformations.size();
}

int main() {
    vector<string> words;
    string input;
    cout << "Enter words separated by spaces (end input with an empty line):" << endl;
    while (getline(cin, input) && !input.empty()) {
        words.push_back(input);
    }

    int result = uniqueMorseRepresentations(words);
    cout << "Number of unique Morse code transformations: " << result << endl;

    return 0;
}
