#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int n;
    cin >>n;
    vector<int> prices;
    int a;
    while(cin >> a) prices.push_back(a);
    int money = prices.back();
    prices.pop_back();
    int l=0, r=0;
    int tot=0, maxCnt =0;
    while( r<n) {
        tot += prices[r];
        while(tot > money) {
            tot -= prices[l];
            l++;
        }
        maxCnt = max(maxCnt, r-l+1);

        r++;
    }
    cout << maxCnt << endl;
    return 0;
}