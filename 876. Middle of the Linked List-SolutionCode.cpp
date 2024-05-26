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

int main() {
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    

    int val;
    ListNode* head = nullptr;
    ListNode* current = nullptr;

    for (int i = 0; i < n; ++i) {
        cout << "Enter the value of the "<<i+1<<" node: ";
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
    ListNode* middle = sol.middleNode(head);
    cout << "The middle node and the rest of the list: " ;

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

    return 0;
}