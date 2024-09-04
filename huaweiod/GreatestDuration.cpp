#include <iostream>
#include <vector>

using namespace std;

int main() {
    int minAve;
    cin >> minAve;
    int n;
    vector<int> losts;
    while(cin >> n) losts.push_back(n);

    n = losts.size();
    vector<int> psum(n+1, 0);
    for(int i=0; i<n; i++)
        psum[i+1] = psum[i]+losts[i];
    
    int maxL =1;
    vector<pair<int, int>> res;
    for(int l=0; l<n; l++) {
        for(int r=l+maxL-1; r<n; r++) {
            int len = r-l+1;
            if(psum[r+1] -psum[l] <= minAve* len) {
                if(len>maxL) {
                    maxL = len;
                    res.clear();
                    res.emplace_back(l, r);
                } else if(len == maxL) {
                    res.emplace_back(l, r);
                }
            }
        }
    }

    for(auto& p: res)
        cout  << p.first<< '-' <<p.second << " ";
    cout <<endl;

    return 0;
}