#include <iostream>
#include <vector>
using namespace std;

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

int main() {
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;

    vector<int> nums(n);
    
    for (int i = 0; i < n; ++i) {
        cout << "Enter the "<<i+1<<" element of the array(in non - decreasing order) : ";
        cin >> nums[i];
    }

    int result = maxCountPositiveAndNegative(nums);
    cout << "Maximum count of positive and negative integers: " << result << endl;

    return 0;
}
