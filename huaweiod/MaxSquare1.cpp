#include <iostream>
#include <algorithm>
 
using namespace std;
const int maxn = 200;

// 正方形内部都是1
int main() {
 
    int M, N;
	cin >> M >> N;
    vector<vector<int>> grid(M, vector<int>(N, 0));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}

    vector<vector<int>> dp(M, vector<int>(N, 0));
    for(int i=0; i<M; i++)
        dp[i][0] = grid[i][0];
    for(int i=0; i<N; i++)
        dp[0][i] = grid[0][i];

    int maxx, maxy, maxl;
	for (int i = 1; i < M; i++) {
		for (int j = 1; j < N; j++) {
			if (grid[i][j] == 0) dp[i][j] = 0;
			else {
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                if (maxl <dp[i][j])
                {
                    maxl = dp[i][j];
                    maxx = i;
                    maxy = j;
                }
			}
		}
	}
    return 0;
}