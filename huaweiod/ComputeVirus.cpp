#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >>n >>m;
    int a, b, t;
    unordered_map<int, vector<pair<int, int>>> g;
    for(int i=0; i<m; i++) {
        cin >>a >>b >>t;
        g[a].push_back({b, t});
    }
    int seed;
    cin>> seed;

    unordered_set<int> vis;
    //[time id]
    using item = pair<int, int>;
    //time min_healp
    priority_queue<item, vector<item>, greater<item>> heap;
    heap.push({0, seed});
    while(!heap.empty()) {
        auto [time, id] = heap.top();
        heap.pop();
        vis.insert(id);
        //all done
        if(n == vis.size()) {
            cout << time<<endl;
            return 0;
        }

        for(const auto& neig : g[id]) {
            if(vis.find(neig.first) == vis.end()) {
                heap.push({time+neig.second, neig.first});
            }
        }

    }

    if(n != vis.size()) {
        cout << -1 <<endl;
    }

    return 0;
}