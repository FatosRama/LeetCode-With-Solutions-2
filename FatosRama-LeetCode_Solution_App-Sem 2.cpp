#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<unordered_map>
#include<unordered_set>


using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution1290 {
public:
    int getDecimalValue(ListNode* head) {
        int num = 0;
        ListNode* current = head;

        while (current != nullptr) {
            num = (num << 1) | current->val;
            current = current->next;
        }

        return num;
    }
};

void linkedlist1290() {


    int digits;
    cout << "Enter the number of digit you want to conver ur binary number(1-8): ";
    cin >> digits;
    int n;
    ListNode* head = nullptr;
    ListNode* current = head;
    for (int i = 0; i < digits; i++) {
        cout << "Enter the " << i + 1 << " number from left to right: ";
        cin >> n;

        ListNode* newNode = new ListNode(n);
        if (head == nullptr) {
            head = newNode;
            current = head;

        }
        else {
            current->next = newNode;
            current = current->next;
        }



    }


    Solution1290 sol;
    int decimalValue = sol.getDecimalValue(head);
    cout << "The decimal value is: " << decimalValue << std::endl;


    current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }


}
class Solution876 {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

void linkedlist876() {
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;



    int val;
    ListNode* head = nullptr;
    ListNode* current = nullptr;

    for (int i = 0; i < n; ++i) {
        cout << "Enter the value of the " << i + 1 << " node: ";
        cin >> val;
        ListNode* newNode = new ListNode(val);

        if (head == nullptr) {
            head = newNode;
            current = head;
        }
        else {
            current->next = newNode;
            current = current->next;
        }
    }

    Solution876 sol;
    ListNode* middle = sol.middleNode(head);
    cout << "The middle node and the rest of the list: ";

    current = middle;
    cout << "[";
    do {

        cout << current->val;
        if (current->next == nullptr) {
            cout << "]" << endl;
        }
        cout << ",";
        current = current->next;


    } while (current != nullptr);

    cout << endl;


    current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }


}
class Solution206 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};

void linkedlist206() {
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;



    ListNode* head = nullptr;
    ListNode* current = nullptr;


    int val;
    for (int i = 0; i < n; ++i) {
        cout << "Enter the values of the nodes:";
        cin >> val;
        ListNode* newNode = new ListNode(val);

        if (head == nullptr) {
            head = newNode;
            current = head;
        }
        else {
            current->next = newNode;
            current = current->next;
        }
    }

    Solution206 sol;
    ListNode* reversedHead = sol.reverseList(head);
    cout << "The reversed linked list: ";


    current = reversedHead;
    cout << "[";
    do {
        cout << current->val;
        if (current->next == nullptr) {
            cout << "]" << endl;
        }
        cout << ",";
        current = current->next;
    } while (current != nullptr);



    current = reversedHead;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

}
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

void linkedlist705() {
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


}
class Solution21 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2)
            return list1 ? list1 : list2;
        if (list1->val > list2->val)
            swap(list1, list2);
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
};

ListNode* createList() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;



    ListNode* head = nullptr;
    ListNode* current = nullptr;

    int val;
    for (int i = 0; i < n; ++i) {
        cout << "Enter the " << i + 1 << " value of the node in sorted order : ";

        cin >> val;
        ListNode* newNode = new ListNode(val);

        if (head == nullptr) {
            head = newNode;
            current = head;
        }
        else {
            current->next = newNode;
            current = current->next;
        }
    }

    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    cout << "[";
    do {
        cout << current->val;
        if (current->next == nullptr) {
            cout << "]" << endl;
            break;
        }
        cout << ",";
        current = current->next;
    } while (current != nullptr);

}

void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

void linkedlist21() {
    cout << "Create the first sorted linked list:" << endl;
    ListNode* list1 = createList();

    cout << "Create the second sorted linked list:" << endl;
    ListNode* list2 = createList();

    Solution21 sol;
    ListNode* mergedList = sol.mergeTwoLists(list1, list2);

    cout << "The merged sorted linked list is:" << endl;
    printList(mergedList);


    freeList(mergedList);


}
class Solution1614 {
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

void stack1614() {
    string s;
    cout << "Enter a valid parentheses string: ";
    cin >> s;

    Solution1614 sol;
    int depth = sol.maxDepth(s);

    cout << "The maximum nesting depth of the parentheses is: " << depth << endl;


}
class Solution1021 {
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

void stack1021() {
    string s;
    cout << "Enter a valid parentheses string: ";
    cin >> s;

    Solution1021 sol;
    string result = sol.removeOuterParentheses(s);

    cout << "The string after removing the outermost parentheses is: " << result << endl;


}
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


void stack1700() {
    vector<int> students;
    vector<int> sandwiches;
    int n, val;

    cout << "Enter the number of students (and sandwiches): ";
    cin >> n;


    for (int i = 0; i < n; ++i) {
        cout << "Enter the preference of " << i + 1 << " student (0 for circular, 1 for square) : ";
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


}
vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    vector<int> answer(n);
    stack<int> s;

    for (int i = 0; i < n; ++i) {

        while (!s.empty() && prices[s.top()] >= prices[i]) {
            answer[s.top()] = prices[s.top()] - prices[i];
            s.pop();
        }
        s.push(i);
    }


    while (!s.empty()) {
        answer[s.top()] = prices[s.top()];
        s.pop();
    }

    return answer;
}

void stack1475() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> prices(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter the price of " << i + 1 << " item: ";
        cin >> prices[i];
    }

    vector<int> result = finalPrices(prices);

    cout << "The final prices with discounts are: ";
    cout << "[";
    for (int price : result) {
        cout << price;
        if (price == result.back()) {
            cout << "]" << endl;
            break;
        }
        else {
            cout << ",";
        }

    }



}
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

void stack682() {
    int n;
    cout << "Enter the number of operations: ";
    cin >> n;

    vector<string> ops(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter the " << i + 1 << " operation: ";
        cin >> ops[i];
    }

    int result = calPoints(ops);
    cout << "The final score is: " << result << endl;


}
int countPairsLessThanTarget(std::vector<int>& nums, int target) {
    int ans = 0;

    for (int i = 0; i < nums.size(); ++i)
        for (int j = i + 1; j < nums.size(); ++j)
            if (nums[i] + nums[j] < target)
                ++ans;

    return ans;
}

void binary_search2824() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter the " << i + 1 << " element: ";
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    int result = countPairsLessThanTarget(nums, target);
    cout << "Number of pairs whose sum is less than target: " << result << std::endl;


}
vector<int> findTargetIndices(vector<int>& nums, int target) {
    vector<int> targetIndices;


    sort(nums.begin(), nums.end());


    for (int i = 0; i < nums.size(); ++i) {

        if (nums[i] == target) {

            targetIndices.push_back(i);
        }
    }

    return targetIndices;
}

void binary_search2089() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter the " << i + 1 << " element: ";
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target element: ";
    cin >> target;

    vector<int> result = findTargetIndices(nums, target);

    cout << "Target indices after sorting: ";
    cout << "[";
    for (int index : result) {
        cout << index;
        if (index == result.back()) {
            cout << "]" << endl;
        }
        else {
            cout << ", ";
        }

    }
    cout << endl;


}
vector<int> maxSubsequenceSizes(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(), nums.end());
    vector<int> answer;

    for (int q : queries) {
        int sum = 0, count = 0;
        for (int num : nums) {
            sum += num;
            if (sum <= q) {
                count++;
            }
            else {
                break;
            }
        }
        answer.push_back(count);
    }

    return answer;
}

void binary_search2389() {
    int n, m;
    cout << "Enter the length of nums array: ";
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter the " << i + 1 << " element of nums array: ";
        cin >> nums[i];
    }

    cout << "Enter the length of queries array: ";
    cin >> m;

    vector<int> queries(m);

    for (int i = 0; i < m; ++i) {
        cout << "Enter the " << i + 1 << " element of queries array: ";
        cin >> queries[i];
    }

    vector<int> result = maxSubsequenceSizes(nums, queries);

    cout << "Maximum sizes of subsequences: ";
    cout << "[";
    for (int val : result) {
        cout << val << ",";

    }
    cout << "]" << endl;


}
int maxCountPositiveAndNegative(vector<int>& nums) {
    int positiveCount = 0, negativeCount = 0;

    for (int num : nums) {
        if (num > 0) {
            positiveCount++;
        }
        else if (num < 0) {
            negativeCount++;
        }
    }

    return max(positiveCount, negativeCount);
}

void binary_search2529() {
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter the " << i + 1 << " element of the array(in non - decreasing order) : ";
        cin >> nums[i];
    }

    int result = maxCountPositiveAndNegative(nums);
    cout << "Maximum count of positive and negative integers: " << result << endl;


}
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int expectedSum = (n * (n + 1)) / 2;
    int actualSum = 0;

    for (int num : nums) {
        actualSum += num;
    }

    return expectedSum - actualSum;
}

void binary_search268() {
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter the " << i + 1 << " element of the array: ";
        cin >> nums[i];
    }

    int result = missingNumber(nums);
    cout << "The missing number is: " << result << endl;


}
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> frequency(101, 0);
    vector<int> prefixSum(101, 0);
    vector<int> result;


    for (int num : nums) {
        frequency[num]++;
    }


    for (int i = 1; i <= 100; ++i) {
        prefixSum[i] = prefixSum[i - 1] + frequency[i - 1];
    }


    for (int num : nums) {
        result.push_back(prefixSum[num]);
    }

    return result;
}

void hashtables1365() {
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter the " << i + 1 << " element of the array: ";
        cin >> nums[i];
    }

    vector<int> result = smallerNumbersThanCurrent(nums);

    cout << "Result: ";
    cout << "[";
    for (int num : result) {
        cout << num;
        if (num == result.back()) {
            cout << "]" << endl;
        }
        else {
            cout << ",";
        }

    }
    cout << endl;


}
int countPairsWithDifference(vector<int>& nums, int k) {
    int count = 0;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (abs(nums[i] - nums[j]) == k) {
                count++;
            }
        }
    }

    return count;
}

void hashtable2006() {

    int n;
    cout << "Enter the length of the array: ";
    cin >> n;
    vector<int>nums1;
    int c;
    for (int i = 0; i < n; i++) {
        cout << "Enter the " << i + 1 << " element of the array: ";
        cin >> c;
        nums1.push_back(c);
    }
    int k;
    cout << "Enter the key: ";
    cin >> k;
    cout << "Number of pairs with absolute difference " << k << ": " << countPairsWithDifference(nums1, k) << endl;

}
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

void hashtable804() {
    vector<string> words;
    string input;
    cout << "Enter words separated by spaces (end input with an empty line):" << endl;
    while (getline(cin, input) && !input.empty()) {
        words.push_back(input);
    }

    int result = uniqueMorseRepresentations(words);
    cout << "Number of unique Morse code transformations: " << result << endl;


}
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

void hashtable2418() {
    vector<string> names;
    vector<int> heights;
    string input;
    int height;

    cout << "Enter names and heights (end input with -1):" << endl;
    while (true) {
        cout << "Enter name: ";
        cin >> input;
        if (input == "-1") break;
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


}
string findDestinationCity(vector<vector<string>>& paths) {
    unordered_map<string, int> g;
    for (vector<string>& path : paths)
        g[path[0]] ++, g[path[1]];

    for (const pair<string, int>& p : g)
        if (p.second == 0) return p.first;
    return "";
}

void hashtable1436() {
    vector<vector<string>> paths;
    string input, cityA, cityB;

    cout << "Enter paths (each path as 'CityA CityB' on a new line, end input with -1):" << endl;
    while (true) {
        getline(cin, input);
        if (input == "-1") break;

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


}


int main() {
    cout << "1.LinkedList" << endl << "2.Stack" << endl << "3.Binary Search" << endl << "4.HashTable" << endl;
    int choose;
    cout << "Choose one out the 4 topics above: ";
    cin >> choose;
    if (choose == 1) {
        int n;
        cout << "Choose a problem from 1-5: ";
        cin >> n;
        switch (n) {
        case 1:
            linkedlist1290();//Space Complexity: O(1), Time Complexity: O(n)
            break;
        case 2:
            linkedlist876();//Space Complexity: O(1), Time Complexity: O(n)
            break;
        case 3:
            linkedlist206();//Space Complexity: O(1), Time Complexity: O(n)
            break;
        case 4:
            linkedlist705();//Space Complexity: O(1), Time Complexity: O(n)
            break;
        case 5:
            linkedlist21();//Space Complexity: O(n), Time Complexity: O(n)
            break;
        default:
            cout << "Invalid number, make sure to type in a number between 1 and 5!" << endl;
        }
    }
     else if(choose == 2) {
        int n;
        cout << "Choose a problem from 1-5: ";
        cin >> n;
        switch (n) {
        case 1:
            stack1614();//Space Complexity: O(1), Time Complexity: O(n)
            break;
        case 2:
            stack1021();//Space Complexity: O(n), Time Complexity: O(n)
            break;
        case 3:
            stack1700();//Space Complexity: O(n), Time Complexity: O(n)
            break;
        case 4:
            stack1475();//Space Complexity: O(n), Time Complexity: O(n)
            break;
        case 5:
            stack682();//Space Complexity: O(n), Time Complexity: O(n)
            break;
        default:
            cout << "Invalid number, make sure to type in a number between 1 and 5!" << endl;
        }
    }
     else if (choose == 3) {
        int n;
        cout << "Choose a problem from 1-5: ";
        cin >> n;
        switch (n) {
        case 1:
            binary_search2824();//Space Complexity: O(1), Time Complexity: O(n^2)
            break;
        case 2:
            binary_search2089();//Space Complexity: O(k), Time Complexity: O(nlogn)
            break;
        case 3:
            binary_search2389();//Space Complexity: O(m), Time Complexity: O(nlogn)
            break;
        case 4:
            binary_search2529();//Space Complexity: O(1), Time Complexity: O(n)
            break;
        case 5:
            binary_search268();//Space Complexity: O(1), Time Complexity: O(n)
            break;
        default:
            cout << "Invalid number, make sure to type in a number between 1 and 5!" << endl;
        }
    }
     else if (choose == 4) {
        int n;
        cout << "Choose a problem from 1-5: ";
        cin >> n;
        switch (n) {
        case 1:
            hashtables1365();//Space Complexity: O(1), Time Complexity: O(n)
            break;
        case 2:
            hashtable2006();//Space Complexity: O(1), Time Complexity: O(n^2)
            break;
        case 3:
            hashtable804();//Space Complexity: O(1)-O(2*m), Time Complexity: O(n*m)
            break;
        case 4:
            hashtable2418();//Space Complexity: O(n), Time Complexity: O(nlogn)
            break;
        case 5:
            hashtable1436();//Space Complexity: O(n), Time Complexity: O(n)
            break;
        default:
            cout << "Invalid number, make sure to type in a number between 1 and 5!" << endl;
        }
    }
}


    
   


