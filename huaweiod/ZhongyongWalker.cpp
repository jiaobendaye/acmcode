#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> visted;
vector<vector<int>> maze;
vector<pair<int, int>> directs {{-1,0},{1,0},{0,-1},{0,1}};
int m , n;

//0:下坡 1: 上坡
int dfs(int i, int j, bool status) {
    visted[i][j] = true;
    int ans = 0;
    for(auto& dir : directs) {
        int nx = i+dir.first;
        int ny = j+dir.second;
        if(nx <0 || nx >=m || ny<0 || ny>=n || visted[nx][ny]) continue;
        if(status) {
            if(maze[nx][ny] > maze[i][j])
                ans = max(dfs(ny,ny,0)+1, ans);
        } else {
            if(maze[nx][ny] < maze[i][j])
                ans = max(dfs(ny,ny,1)+1, ans);
        }
    }
    visted[i][j] = false;
    return ans;
}
int main() {
    cin >>m >> n;
    maze.resize(m, vector<int>(n,0));
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> maze[i][j];
        }
    }
    visted.resize(m, vector<bool>(n,false));
    int ans = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            ans = max(ans, dfs(i, j, 0));
            ans = max(ans, dfs(i, j, 1));
        }
    }
    cout << ans << endl;

    return 0;
}