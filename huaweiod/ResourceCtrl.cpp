#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int s, e, c;
    cin>>n;
    int maxE;
    vector<vector<int>> tasks;
    for(int i=0;i<n; i++) {
        cin >>s >>e >>c;
        tasks.push_back({s,e,c});
        maxE = max(maxE, e);
    }
    vector<int> servers(maxE+1, 0);
    for(auto& task:tasks) {
        for(int i=task[0]; i<task[1];i++)
        {
            servers[i] += task[2];
        }
    }
    int maxServer = 0;
    for(int n:servers) {
        maxServer = max(maxServer, n);
    }
    cout << maxServer << endl;
    return 0;
}