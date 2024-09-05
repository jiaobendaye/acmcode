#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>

using namespace std;
int main() {
    int n, m;
    cin >>n >>m;
    vector<int> order;
    int a;
    for(int i=0; i<n; i++) {
        cin >>a;
        if(a==m) {
            order.push_back(a<0?a-1:a+1);
        } else {
            order.push_back(a);
        }
    }

    int maxX = 0;
    int x =0;
    for(int d:order){
        x += d;
        maxX = max(maxX, x);
    }

    cout << maxX << endl;
    return 0;
}