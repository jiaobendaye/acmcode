#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

inline void printVec(const vector<int> vec)
{
    for(int x:vec)
        cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> nums;
    string str;
    getline(cin ,str);
    istringstream iss(str);
    while(getline(iss, str, ',')){
        nums.push_back(stoi(str));
    }
    int target = 0;
    cin>>target;
    vector<int> psum(nums.size(), 0);
    psum[0] = nums[0];
    for(int i=1;i<psum.size(); i++) {
        psum[i] = psum[i-1] + nums[i];
    }
    printVec(nums);
    printVec(psum);

    int ans;
    for(int i=0; i<nums.size(); i++) {
        for(int j=i+1; j<nums.size(); j++) {
            if(psum[j]-psum[i] == target) {
                ans = max(ans, j-i+1);
            }
        }
    }
    cout << ans <<endl;

    ans = 0;
    unordered_map<int, int> dict;
    dict[0] = 0;
    int presum =0;
    for(int i=0; i<nums.size(); i++) {
        presum += nums[i];
        int remove = presum - target;
        if(dict.find(remove) != dict.end()) {
            ans = max(ans, i-dict[remove]+1);
        }
        dict[presum] = i;
    }

    cout << ans <<endl;
    return 0;
}