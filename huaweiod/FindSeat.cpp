#include <iostream>
#include <vector>

using namespace std;

int main() {
    string seat;
    cin >> seat;

    int result = 0, n = seat.length();

    // pre 用于表示前一个座位的状态， 0表示该座位没有坐人，1表示该座位已经坐人
    char pre = '0';
    for(int i = 0; i < n; i++) {
        // seat[i] 没有人座 且两边都没有人座
        if(pre == '0' && seat[i] == '0' and (i + 1 == n or seat[i+1] == '0')) {
            result++;
            pre = '1';
            continue;
        }
        pre = seat[i];
    }

    cout << result << endl;

    return 0;
}