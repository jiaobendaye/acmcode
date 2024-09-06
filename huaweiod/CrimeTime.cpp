#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

using HH = int;
using MM = int;

// 按HH：MM排序
// bool cmp(const pair<int, int>& l, const pair<int,int>& r) {
//     if(l.first != r.first) {
//         return l.first < r.first;
//     }
//     return l.second < r.second;
// }

inline void print(const vector<pair<int, int>>& v)
{
    for(auto& p : v) {
        cout << p.first << "." << p.second << " ";
    }
    cout << endl;
}

int main() {
    string seg;
    string line;
    getline(cin, line);
    set<int> cnt;
    for(char c:line){
        if(isdigit(c)) cnt.insert(c-'0');
    }
    istringstream iss(line);
    
    int HH, MM;
    vector<int> v;
    while(getline(iss, seg, ':')) {
        v.push_back(stoi(seg));
    }
    pair<int, int> now = {v[0], v[1]};
    vector<pair<int, int>> all_points;
    // all_points.push_back(now);
    vector<pair<int, int>> late_points;
    vector<pair<int, int>> early_points;
    for(int a:cnt) {
        for(int b:cnt) {
            for(int c:cnt) {
                for(int d:cnt) {
                    int h= a*10+b;
                    int m = c*10+d;
                    if(h<=24 && m <=60) {
                        if(h==24) h=0;
                        all_points.push_back({h, m});
                    }
                }
            }
        }
    }

    sort(all_points.begin(), all_points.end());
    print(all_points);
    int pos = lower_bound(all_points.begin(), all_points.end(), now) - all_points.begin();
    auto res =all_points[(pos+1)%all_points.size()]; 
    cout << res.first << ":" << res.second << endl;

    return 0;
}