#include <iostream>
#include <vector>
using namespace std;

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

int main() {
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;

    vector<int> nums(n);
    
    for (int i = 0; i < n; ++i) {
        cout << "Enter the "<<i+1<<" element of the array: ";
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

    return 0;
}
