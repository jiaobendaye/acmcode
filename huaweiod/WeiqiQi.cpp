#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;
inline void print(vector<pair<int, int>>& v) {
    for(auto& p:v) {
        cout << p.first << "," <<p.second << ". ";
    }
    cout << endl;
}

vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

bool check(int x, int y) {
    return x >=0 && x<19 && y>=0 && y<19;
}

int main() {
    string line;
    set<pair<int, int>> black;
    set<pair<int, int>> withe;
    int a, b;
    getline(cin, line);
    istringstream iss(line);
    while(iss >>a >>b) black.insert({a, b});
    getline(cin, line);
    istringstream iss2(line);
    while(iss2 >>a >>b) withe.insert({a, b});
    // print(withe);
    // print(black);
    set<pair<int, int>> bq;
    set<pair<int, int>> wq;
    for(auto [x,y] : black) {
        for(auto [dx, dy] : dirs) {
            int nx = x+dx;
            int ny = y+dy;
            pair<int, int> point = {nx, ny};
            if(check(nx, ny) && black.count(point)==0 && withe.count(point) == 0) {
                bq.insert(point);
            }
        }
    }
    for(auto [x,y] : withe) {
        for(auto [dx, dy] : dirs) {
            int nx = x+dx;
            int ny = y+dy;
            pair<int, int> point = {nx, ny};
            if(check(nx, ny) && black.count(point)==0 && withe.count(point) == 0) {
                wq.insert(point);
            }
        }
    }
    cout << bq.size() << " " << wq.size() << endl;
    return 0;
}