#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
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

int main() {

    
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


    Solution sol;
    int decimalValue = sol.getDecimalValue(head);
    cout << "The decimal value is: " << decimalValue << std::endl;


    current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
