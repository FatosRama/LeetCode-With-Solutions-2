#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> finalPrices(std::vector<int>& prices) {
    int n = prices.size();
    vector<int> answer(n);
    stack<int> s;

    for (int i = 0; i < n; ++i) {
 
        while (!s.empty() && prices[s.top()] >= prices[i]) {
            answer[s.top()] = prices[s.top()] - prices[i];
            s.pop();
        }
        s.push(i);
    }

   
    while (!s.empty()) {
        answer[s.top()] = prices[s.top()];
        s.pop();
    }

    return answer;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> prices(n);
    
    for (int i = 0; i < n; ++i) {
        cout << "Enter the price of "<<i+1<<" item: ";
        cin >> prices[i];
    }

    vector<int> result = finalPrices(prices);

    cout << "The final prices with discounts are: ";
    cout << "[";
    for (int price : result) {
        cout << price;
        if (price == result.back()) {
            cout << "]" << endl;
            break;
        }
        else {
           cout  << ",";
        }
        
    }
    

    return 0;
}
