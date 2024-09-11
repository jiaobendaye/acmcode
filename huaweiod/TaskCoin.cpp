#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>

using namespace std;
int main() {
    int n, t;
    cin >>n >>t;
    vector<pair<int, int>> tasks;
    int e, c;
    for(int i=0; i<n; i++) {
        cin >>e >>c;
        tasks.emplace_back(e, c);
    }
    sort(tasks.begin(), tasks.end());
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int res = 0;
    for(auto [e, c] :tasks){
        res +=c;
        minHeap.push(c);
        while (e < minHeap.size() || minHeap.size() > t) {
            res -= minHeap.top();
            minHeap.pop();
        }
    }
    cout << res <<endl;
    return 0;
}