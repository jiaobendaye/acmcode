#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n ,E;
    cin >>n >>E;
    int X, offsetY;
    long long totArea = 0;
    int x=0, y=0;
    for(int i=0; i<n; i++) {
        cin >> X >> offsetY;
        totArea += (X-x) * abs(y);
        x = X;
        y = y+offsetY;
    }
    totArea += (E-x) * abs(y);
    cout << totArea << endl;
    return 0;
}