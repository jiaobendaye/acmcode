#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int M, N;
    cin >>M >>N;
    vector<int> speeds(M);
    for(int i=0; i<M; i++) {
        cin>>speeds[i];
    }
    float lastArriTime;
    for(int i=0; i<M; i++) {
        int s = speeds[i];
        lastArriTime = max(lastArriTime, (float)N/s + i);
    }
    cout << lastArriTime-M+1 <<endl;
    return 0;
}