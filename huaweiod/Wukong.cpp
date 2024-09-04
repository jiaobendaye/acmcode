#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> peachs;
int H;
bool ok(int speed )
{
    int times;
    for(int p: peachs) {
        times += ceil(((float) p)/speed);
    }
    if(times <= H) return true;
    return false;
}

int main() {
    int n;
    while(cin >>n) peachs.push_back(n);
    H = peachs.back();
    peachs.pop_back();
    n = peachs.size();

    // cout<<endl<<"size: " << peachs.size() << H <<endl;
    if(n>H) {
        cout << 0 <<endl;
        return 0;
    } 
    int l=0, r=*max_element(peachs.begin(), peachs.end());
    while(l+1<r) {
        int mid = l+ (r-l)/2;
        if(ok(mid)) {
            r = mid;
        } else  {
            l = mid;
        }
    }

    cout << r <<endl;
    return 0;
}
