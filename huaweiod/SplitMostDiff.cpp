#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n;
    cin >>n;
    vector<int> inputs(n, 0);
    for(int i=0; i<n;i++) {
        cin >>inputs[i];
    }
    vector<int> psum(n, 0);
    psum[0] = inputs[0];
    for(int i=1; i<n; i++) {
        psum[i] = psum[i-1] + inputs[i];
    }
    int ans = 0;
    for(int i=1; i<n-1; i++)
    {
        int diff = abs(psum[n-1] - 2*psum[i]);
        ans = max(ans, diff);
    }

    cout  << ans << endl;
    return 0;
}