#include <iostream>
#include <vector>
#include <string>

using namespace std;

//完全背包
int main() {
    int M;
    cin >>M;
    int t;
    vector<int> p;
    while(cin>>t) {
        p.push_back(t);
    }

    vector<int> dp(M+1, 0);
    for(int i=1; i<p.size()-1; i++) {
        int cnt = p[i-1];
        for(int j=i; j<=M; j++) {
            dp[j] = max(dp[j], dp[j-i]+cnt);
        }
    }

    cout << dp[M] <<endl;
    return 0;
}