#include <iostream>
#include <vector>
#include <string>
using namespace std;

int M, N;
vector<vector<int>> grid;

vector<pair<int, int>> directions = {{-1, 0}, {1,0}, {0,-1}, {0, 1}};

bool checkxy(int x, int y) {
    return (x >=0 && x < M && y>=0 && y <N);
}

int dfs(int x, int y, vector<vector<bool>>& vis)
{
    // if(!checkxy(x, y) || vis[x][y]) return 0;
    int ans = 0;

    vis[x][y] = true;
    for(auto& dir:directions)
    {
        int nx = x + dir.first;
        int ny = y + dir.second;
        if(checkxy(nx, ny) && vis[nx][ny] ==false && abs(grid[nx][ny] - grid[x][y]) <=1)
            ans += dfs(nx, ny, vis);
    }
    vis[x][y] = false;
    return ans+1;
}

int main() {
    cin >>M >>N;
    grid.resize(M, vector<int>(N, 0));
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            cin >>grid[i][j];
        }
    }
    int ans = 0;
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            vector<vector<bool>> vis(M, vector<bool>(N, false));
            ans = max(ans, dfs(i, j, vis));
        }
    }

    cout << ans <<endl;

    return 0;
}