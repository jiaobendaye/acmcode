#include <iostream>
#include <algorithm>
 
using namespace std;
int H, W;
vector<vector<int>> grid;
vector<vector<int>> rowPsum;
vector<vector<int>> colPsum;

inline bool check(int x, int y, int w) {
    if(rowPsum[x][y] < w || colPsum[x][y] < w) return false;
    if(rowPsum[x-w+1][y] < w || colPsum[x][y-w+1] < w) return false;
    return true;
}

void print(const vector<vector<int>>& m)
{
    for(auto& v : m) {
        for(int n: v) {
            cout << n << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >>H >>W;
    grid.resize(H, vector<int>(W,0));
    rowPsum.resize(H, vector<int>(W,0));
    colPsum.resize(H, vector<int>(W,0));
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >>grid[i][j];
        }
    }
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            if(grid[i][j] == 0) continue;
            rowPsum[i][j] = (j>0?rowPsum[i][j-1]:0)+1;
            colPsum[i][j] = (i>0?colPsum[i-1][j]:0)+1;
        }
    }
    /*
    cout << "grid:" <<endl;
    print(grid);
    cout << "rowPsum:" <<endl;
    print(rowPsum);
    cout << "colPsum:" <<endl;
    print(colPsum);
    */
    int x=0, y=0, w=0;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            if(grid[i][j] == 0) continue;
            for(int l =min(rowPsum[i][j], colPsum[i][j]); l > w; l--) {
                if(check(i, j, l)) {
                    w =l; x =i; y =j; break;
                }
            }
        }
    }
    cout <<"["<<x<<","<<y<<","<<w<<"]"<<endl;
    return 0;
}