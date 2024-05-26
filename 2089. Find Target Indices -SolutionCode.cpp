#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


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

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    
    for (int i = 0; i < n; ++i) {
        cout << "Enter the "<<i+1<<" element: ";
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

    return 0;
}
