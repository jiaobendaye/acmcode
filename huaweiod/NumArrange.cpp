#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n;
    int maxN;
    set<int> nums;
    string seg;
    while(getline(cin, seg, ',')) {
        n = stoi(seg);
        if(n<=0 || n >9) {
            cout << -1 << endl;
            return 0;
        }
        maxN = max(maxN, n);
        nums.insert(n);
    }
    if((nums.count(6) && nums.count(9))||  (nums.count(2) && nums.count(5))) {
            cout << -1 << endl;
            return 0;
    }
    if(nums.count(6)) nums.insert(9);
    if(nums.count(9)) nums.insert(6);
    if(nums.count(2)) nums.insert(5);
    if(nums.count(5)) nums.insert(2);
    // cout << "size: "<<nums.size() << endl;
    vector<int> numsVec;
    numsVec.assign(nums.begin(), nums.end());
    for(int n : nums) {
        for(int c:nums) {
            if(c!=n) numsVec.push_back(n*10+c);
        }
    }
    sort(numsVec.begin(), numsVec.end());
    // for(int n : numsVec) {
    //     cout << n << " ";
    // }
    cout << numsVec[maxN-1] <<endl;

    return 0;
}