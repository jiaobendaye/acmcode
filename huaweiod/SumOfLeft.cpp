#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int sumOfLeft(vector<int> nums, int jump, int left) {
        int cnt = nums.size() - left;

        for(int i=0, idx = 1; i < cnt; i++) {
            idx = (idx + jump) % nums.size();
            nums.erase(nums.begin() + idx);
        }

        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        return sum;
    }
};
int main() {
    Solution sol;
    cout << sol.sumOfLeft({1,2,3,4,5,6,7,8,9}, 4,3) << endl;
    return 0;
}