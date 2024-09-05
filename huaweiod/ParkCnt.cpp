#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int main() {
    string seg;
    vector<int> p;
    while(getline(cin, seg, ',')) p.push_back(seg[0] == '1');
    // for(int n : p)
    //     cout << n << " ";
    // cout << endl;
    vector<int> cnt;
    int sum = 0;
    for(int n:p){
        if(n==1) {
            sum++;
        }else if(sum >0) {
            cnt.push_back(sum);
            sum=0;
        }
    }
    if(sum>0) cnt.push_back(sum);
    // for(int n : cnt)
    //     cout << n << " ";
    // cout << endl;
    int res=0;
    for(int n:cnt) {
        while(n>0) {
            if(n>=3) {
                n-=3;
                res++;
            }else if(n>=2) {
                n-=2;
                res++;
            }else if(n>=1) {
                n--;
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}