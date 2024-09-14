#include <iostream>
#include <algorithm>
#include <sstream>
 
using namespace std;
vector<int> path;
vector<bool> vis;
vector<int>   a;
vector<int>   b;
int ans;
int n;
int maxWinCnt;

void dfs(int idx ,int cnt) {
    if(idx == n) {
        if(cnt > maxWinCnt) {
            maxWinCnt = cnt;
            ans=1;
        } else if(cnt == maxWinCnt) {
            ans++;
        }
        return;
    }
    for(int i=0; i<n;i++) {
        if(vis[i]) continue;
        vis[i] = true;
        dfs(idx+1, cnt+(a[i] > b[idx]?1:0));
        vis[i] = false;
    }
}


int main() {
    string line1;
    string line2;
    getline(cin,line1);
    getline(cin,line2);

    string seg;
    istringstream iss1(line1);
    while(getline(iss1, seg, ' ')) a.push_back(stoi(seg));
    n = a.size();
    vis.resize(n, false);
    istringstream iss2(line2);
    while(getline(iss2, seg, ' ')) b.push_back(stoi(seg));
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}