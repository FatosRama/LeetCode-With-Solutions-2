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
        cout << "Enter the "<<i+1<<" value of the node in sorted order : ";
        
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
    do{
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

int main() {
    cout << "Create the first sorted linked list:" << endl;
    ListNode* list1 = createList();

    cout << "Create the second sorted linked list:" << endl;
    ListNode* list2 = createList();

    Solution sol;
    ListNode* mergedList = sol.mergeTwoLists(list1, list2);

    cout << "The merged sorted linked list is:" << endl;
    printList(mergedList);

   
    freeList(mergedList);

    return 0;
}
