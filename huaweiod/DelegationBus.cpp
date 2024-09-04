#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string inputStr;
    getline(cin, inputStr);
    stringstream ss(inputStr); // 使用流输入
    int m, num;
    vector<int> a;

    while (ss >> num) {
        a.push_back(num);
        if (ss.peek() == ',') {
            ss.ignore();
        }
    }

    cin >> m;
    vector<int> dp(m + 1, 0); // dp[n]表示恰好装成容量为n的方案数
    dp[0] = 1; // 初始化dp[0] = 1,表示容量为0的方案为1种

    for (int i : a) {
        for (int j = m; j >= i; j--) {
            dp[j] += dp[j - i]; // 转移方程为：dp[n] += dp[n - i]
        }
    }

    cout << dp[m] << endl;

    return 0;
}