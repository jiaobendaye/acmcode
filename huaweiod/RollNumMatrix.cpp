#include <iostream>
#include <vector>

using namespace std;

/*
 ------> c
 |
 |
 r
*/
vector<pair<int,int>> directions = {{0,1}, {1,0},{0,-1}, {-1,0}};
vector<vector<int>> grid;
int d =0;
int n, m, col;

inline void printM(const vector<vector<int>> m) {
    for(auto& line : m) {
        for(int x : line) {
            if( x == 0)
                cout << "*" << " ";
            else
                cout << x << " ";
        }
        cout << endl;
    }
}

void dfs(int r, int c, int cur) {
    if(cur>n) return;
    if(r <0 || r>=grid.size() || c <0|| c>=grid[0].size() || grid[r][c]!=0)
    {
        r -= directions[d].first;
        c -= directions[d].second;
        cur--;
        d = (d+1)%4;
    } else if(grid[r][c] == 0) {
        grid[r][c] = cur;
    }
    dfs(r+directions[d].first, c+directions[d].second, cur+1);
}

int main() {
    cin>>n >>m;
    col = (n/m)+1;
    grid.resize(m, vector<int>(col, 0));
    dfs(0,0,1);
    printM(grid);
    return 0;
}