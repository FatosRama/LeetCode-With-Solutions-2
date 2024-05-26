#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> maxSubsequenceSizes(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(), nums.end());
    vector<int> answer;

    for (int q : queries) {
        int sum = 0, count = 0;
        for (int num : nums) {
            sum += num;
            if (sum <= q) {
                count++;
            }
            else {
                break;
            }
        }
        answer.push_back(count);
    }

    return answer;
}

int main() {
    int n, m;
    cout << "Enter the length of nums array: ";
    cin >> n;

    vector<int> nums(n);
    
    for (int i = 0; i < n; ++i) {
        cout << "Enter the "<<i+1<<" element of nums array: ";
        cin >> nums[i];
    }

    cout << "Enter the length of queries array: ";
    cin >> m;

   vector<int> queries(m);
    
    for (int i = 0; i < m; ++i) {
        cout << "Enter the "<<i+1<<" element of queries array: ";
        cin >> queries[i];
    }

    vector<int> result = maxSubsequenceSizes(nums, queries);

    cout << "Maximum sizes of subsequences: ";
    cout << "[";
    for (int val : result) {
        cout << val << ",";
        
    }
    cout << "]"<<endl;

    return 0;
}
