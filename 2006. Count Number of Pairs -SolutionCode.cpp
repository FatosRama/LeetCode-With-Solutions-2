#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

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

int main() {
  
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

    return 0;
}
