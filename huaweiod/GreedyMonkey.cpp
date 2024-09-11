#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, cnt;
    cin >> n;
    vector<int> vec(n, 0);
    for(int i=0; i<n; i++)
        cin>>vec[i];
    cin >>cnt;
    int sum = 0;
    for(int i=0; i<cnt; i++) sum += vec[i];
    int res = sum;
    int left=cnt-1;
    int right = n-1;
    while(left >=0) {
        sum += vec[right--] - vec[left--];
        res = max(res, sum);
    }
    cout << res << endl;
    return 0;
}