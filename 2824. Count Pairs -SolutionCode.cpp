#include <iostream>
#include <vector>

using namespace std;

int countPairsLessThanTarget(std::vector<int>& nums, int target) {
    int ans = 0;

    for (int i = 0; i < nums.size(); ++i)
        for (int j = i + 1; j < nums.size(); ++j)
            if (nums[i] + nums[j] < target)
                ++ans;

    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
   
    for (int i = 0; i < n; ++i) {
        cout << "Enter the "<<i+1<<" element: ";
        std::cin >> nums[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    int result = countPairsLessThanTarget(nums, target);
    cout << "Number of pairs whose sum is less than target: " << result << std::endl;

    return 0;
}
