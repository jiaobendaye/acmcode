#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tasks;
vector<int> workers;
bool ok(int idx, int target)
{
    if(idx >= tasks.size()) return true;
    for(int i=0; i<workers.size(); i++)
    {
        if(workers[i] + tasks[idx] <= target) {
            workers[i] += tasks[idx];
            if(ok(idx+1, target)){
                return true;
            }
            workers[i] -= tasks[idx];
        }
    }
    return false;
}

int main() {
    int x;
    while(cin >> x) tasks.push_back(x);
    int N = tasks.back();
    workers.resize(N);
    tasks.pop_back();
    int maxC, sumC;
    for(int a : tasks) {
        maxC = max(maxC, a);
        sumC += a;
    }
    // cout << N << " " << maxC << " " << sumC << endl;
    int l = maxC, r = sumC;
    while(l+1< r) {
        int mid = l+(r-l)/2;
        workers.clear();
        workers.resize(N, 0);
        if(ok(0, mid)) {
            r = mid;
        } else {
            l= mid;
        }
    }
    cout << r << endl;
    return 0;
}