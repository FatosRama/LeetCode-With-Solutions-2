#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int expectedSum = (n * (n + 1)) / 2;
    int actualSum = 0;

    for (int num : nums) {
        actualSum += num;
    }

    return expectedSum - actualSum;
}

int main() {
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;

    vector<int> nums(n);
    
    for (int i = 0; i < n; ++i) {
        cout << "Enter the "<<i+1<<" element of the array: ";
        cin >> nums[i];
    }

    int result = missingNumber(nums);
    cout << "The missing number is: " << result << endl;

    return 0;
}
