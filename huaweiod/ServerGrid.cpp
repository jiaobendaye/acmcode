#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<vector<int>> serves;
vector<pair<int, int>> directs = {{-1,0},{1,0}, {0,-1}, {0,1}};

int dfs(int i, int j) {
    if(i<0 || i>=n || j<0 || j>=m || serves[i][j] == 0) return 0;
    int cnt = 1;
    serves[i][j] = 0;
    for(auto& dir : directs) {
        cnt += dfs(i+dir.first, j+dir.second);
    }
    return cnt;
}

int main() {
    // n = 2, m =2;
    // serves = {{1, 0}, {1, 1}};
    cin >>n >>m;
    serves.resize(n, vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin>> serves[i][j];
        }
    }
    int res = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            if(serves[i][j] ==1)
            {
                res = max(dfs(i, j), res);
            }
        }
    }

    cout << res << endl;

    return 0;
}