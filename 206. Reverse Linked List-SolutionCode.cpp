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

int main() {
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

    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);
    cout << "The reversed linked list: " ;

    
    current = reversedHead;
    cout << "[";
     do{
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

    return 0;
}
