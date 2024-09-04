#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int main() {
    int T,N;
    cin >>T >>N;
    int c;
    for(int i=0;i<(N+2-1); i++) {
        cin >>c;
        T-=c;
    }
    // vector<pair<int, int>> money(N);
    priority_queue<pair<int, int>> heap;
    int m, d;
    for(int i=0;i<N; i++) {
        cin >>m >>d;
        heap.push({m,d});
        // cin>>money[i].first>>money[i].second;
    }
    // 
    int ans = 0;
    for(int i=0; i<T;i++) {
        auto [m ,d] = heap.top();
        heap.pop();
        ans += m;
        if(m-d >0) {
            heap.push({m-d, d});
        }
        if(heap.empty()) break;
    }
    cout << ans <<endl;

/*
    vector<vector<int>> dp(N+1, vector<int>(T+1, 0));
    for(int n=0; n<N; n++) {
        int m=money[n].first, d= money[n].second, all=0;
        for(int waitDay=0; waitDay<=T; waitDay++) {
            for(int day=waitDay; day<=T; day++) {
                dp[n+1][day] = max(dp[n+1][day], dp[n][day-waitDay]+all);
            }

            all+=m;
            m= max(0, m-d);
        }
    }

    cout << dp[N][T];
*/
    return 0;
}