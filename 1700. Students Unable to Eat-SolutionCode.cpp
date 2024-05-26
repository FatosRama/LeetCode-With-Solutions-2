#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> studentQueue;
    queue<int> sandwichStack;

    for (int student : students) {
        studentQueue.push(student);
    }

    for (int sandwich : sandwiches) {
        sandwichStack.push(sandwich);
    }

    int unableToEatCount = 0;
    while (!studentQueue.empty()) {
        if (studentQueue.front() == sandwichStack.front()) {
            studentQueue.pop();
            sandwichStack.pop();
            unableToEatCount = 0;
        }
        else {
            studentQueue.push(studentQueue.front());
            studentQueue.pop();
            unableToEatCount++;

            
            if (unableToEatCount == studentQueue.size()) {
                break;
            }
        }
    }

    return unableToEatCount;
}


int main() {
    vector<int> students;
    vector<int> sandwiches;
    int n, val;

    cout << "Enter the number of students (and sandwiches): ";
    cin >> n;

   
    for (int i = 0; i < n; ++i) {
        cout << "Enter the preference of "<<i+1<<" student (0 for circular, 1 for square) : ";
        cin >> val;
        students.push_back(val);
    }

    
    for (int i = 0; i < n; ++i) {
        cout << "Enter the type of sandwiches (0 for circular, 1 for square) in stack order: ";
        cin >> val;
        sandwiches.push_back(val);
    }

    int result = countStudents(students, sandwiches);
    cout << "Number of students unable to eat: " << result << endl;

    return 0;
}
