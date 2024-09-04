#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;
int main() {
    int n;
    cin >>n;
    int a;
    priority_queue<int> weis;
    for(int i=0; i<n; i++)
    {
         cin>>a;
         weis.push(a);
    }
    while(weis.size()>=3)
    {
        int z = weis.top();
        weis.pop();
        int y = weis.top();
        weis.pop();
        int x = weis.top();
        weis.pop();
        int left = 0;
        if(x == y && y == z){
        }
        else if(x == y && y !=z) {
            left =  z-y;
        } else if(x !=y && y==z) {
            left =  y-x;
        } else if(x !=y && y!=z) {
            left = abs((z-y) - (y-x));
        }
        if(left>0)
            weis.push(left);
    }
    if(weis.empty()) {
        cout << 0 << endl;
    } else {
        cout << weis.top() << endl;
    }
    return 0;
}