#include <iostream>
#include <vector>
#include <string>
using namespace std;


class MyHashSet {
private:
    vector<bool> data;
public:
    MyHashSet() : data(1000001, false) {}

    void add(int key) {
        data[key] = true;
    }

    bool contains(int key) {
        return data[key];
    }

    void remove(int key) {
        data[key] = false;
    }
};

int main() {
    MyHashSet myHashSet;

    while (true) {
        string operation;
        cout << "Choose an operation: add, contains, remove, or exit: ";
        cin >> operation;

        if (operation == "exit") {
            break;
        }

        int key;
        cout << "Enter key: ";
        cin >> key;

        if (operation == "add") {
            myHashSet.add(key);
            cout << "Added key " << key << endl;
        }
        else if (operation == "contains") {
            bool result = myHashSet.contains(key);
            cout << "Contains key " << key << ": " << (result ? "true" : "false") << endl;
        }
        else if (operation == "remove") {
            myHashSet.remove(key);
            cout << "Removed key " << key << endl;
        }
        else {
            cout << "Invalid operation. Please choose add, contains, remove, or exit." << endl;
        }
    }

    return 0;
}
