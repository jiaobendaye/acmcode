#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int ans = INT_MAX;
int allsum =0;
vector<int> nums;

void helper(int idx, int c, int sum)
{
    if(c == nums.size() /2) {
        ans = min(ans, allsum - 2*sum);
        return;
    }
    for(int i=idx; i<nums.size(); i++){
        helper(i+1, c, sum);
        helper(i+1, c+1, sum+nums[i]);
    }
}

int main() {
    int n;
    while(cin>> n){
        allsum +=n;
        nums.push_back(n);
    } 
    helper(0, 0,0);
    cout << ans << endl;
    return 0;
}