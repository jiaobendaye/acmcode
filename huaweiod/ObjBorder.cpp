#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>

using namespace std;
int M, N;
vector<vector<int>> grid;

bool check(int x, int y) {
    return (x >=0 && x<M && y>=0 && y<N);
}

void dfs(int x, int y) {
    if(!check(x,y) || grid[x][y]!=0) return;
    grid[x][y] = 1;
    for(int dx=-1; dx<2; dx++) {
        for(int dy=-1; dy<2; dy++) {
            dfs(x+dx, y+dy);
        }
    }
}

int main() {
    cin >>M >>N;
    grid.resize(M, vector<int>(N, 0));
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            cin >>grid[i][j];
        }
    }
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(grid[i][j] == 5) {
                for(int dx=-1; dx<2; dx++) {
                    for(int dy=-1; dy<2; dy++) {
                        int nx = i+dx, ny = j+dy;
                        if(check(nx, ny)) {
                            grid[nx][ny] = 0;
                        }
                    }
                }
            }
        }
    }

    int res = 0;
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(grid[i][j] == 0) {
                dfs(i, j);
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}