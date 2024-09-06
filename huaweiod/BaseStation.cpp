#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<bool>> visited;
vector<vector<int>> grid;
int Th, M, N, K;
int ans = INT_MAX;

vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

inline bool checkxy(int x, int y) {
    return (x >=0 && x<grid.size() && y>=0 && y<grid[0].size());
}


void update(int x, int y, int strong) {
    if(checkxy(x,y)) grid[x][y] = max(strong, grid[x][y]);
    for(auto& dir:directions) {
        int nx = x, ny = y;
        int left = strong-1;
        while(left >0 ){
            nx += dir.first, ny += dir.second;
            if(checkxy(nx, ny)){
                grid[nx][ny] = max(grid[nx][ny], left);
                left--;
            } else {
                break;
            } 
        }
    }
}

void dfs(int x, int y, int step) {
    if(!checkxy(x, y) || visited[x][y] || grid[x][y] <Th ) return;
    visited[x][y]= 1;
    if(x == M-1 && y == N-1) {
        ans = min(ans, step);
        return;
    }

    for(auto& dir:directions) {
        dfs(x+dir.first, y+dir.second, step+1);
    }
    visited[x][y]= 0;
}

int main() {
    cin >>Th >>M >>N >>K;
    grid.resize(M, vector<int>(N, 0));
    visited.resize(M, vector<bool>(N, false));
    int x, y, strong;
    for(int i=0; i<K; i++) {
        cin >>x >>y >>strong;
        update(x, y, strong);
    }
    dfs(0,0,0);
    if(ans == INT_MAX)
        cout << 0 << endl;
    else
        cout << ans << endl;

    return 0;
}