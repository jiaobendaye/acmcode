#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int m=s1.size(), n=s2.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1, INT_MAX));
    dp[0][0] = 0;
    for(int r=0; r<m; r++) {
        dp[r+1][0] =dp[r][0]+1; 
    }
    for(int c=0; c<n; c++) {
        dp[0][c+1] =dp[0][c]+1; 
    }

    for(int r=1; r<=m; r++) {
        for(int c=1; c<=n; c++) {
            dp[r][c] = min(dp[r-1][c], dp[r][c-1])+1;
            if(s1[r-1] == s2[c-1]) 
                dp[r][c] = min(dp[r-1][c-1]+1, dp[r][c]);
        }
    }

    cout << dp[m][n] <<endl;
    return 0;
}