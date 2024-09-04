#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

vector<int> father;

int find(int x) {
    if(father[x] == 0) father[x] = x;
    if(father[x] != x ) father[x] = find(father[x]);
    return father[x];
}

void merge(int x, int y) {
    int xRoot = find(x);
    int yRoot = find(y);
    if(xRoot == yRoot) return;
    father[xRoot] = yRoot;
}

int main() {
    int N;
    cin >>N;
    father.resize(N+1, 0);
    cin.ignore();
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> positive;
    string seg;
    while(getline(iss, seg, ',')) positive.push_back(stoi(seg));
    for(int i=1; i<N+1; i++) {
        getline(cin, line);
        vector<int> ns;
        istringstream iss(line);
        while(getline(iss, seg, ',')) {
            merge(i, stoi(seg));
        }
    }
    set<int> all(positive.begin(), positive.end());
    for(int i=1; i<=N; i++) {
        for(int p : positive) {
            if(find(p) == find(i)) all.insert(i);
        }
    }
    cout << all.size()-positive.size() << endl;
    return 0;
}