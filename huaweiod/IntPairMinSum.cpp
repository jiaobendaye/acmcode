#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    vector<int> nums1;
    vector<int> nums2;
    cin>>n;
    nums1.resize(n);
    for(int i=0; i<n; i++)
        cin>>nums1[i];
    cin>>n;
    nums2.resize(n);
    for(int i=0; i<n; i++)
        cin>>nums2[i];
    int k;
    cin >>k;
    vector<int> pairS;
    for(int a : nums1) {
        for(int b:nums2) {
            pairS.push_back(a+b);
        }
    }
    sort(pairS.begin(), pairS.end());
    int ans = 0;
    for(int i=0; i<k&&i<pairS.size(); i++)
         ans += pairS[i];
    cout << ans << endl;
    return 0;
}