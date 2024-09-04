#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct  Item
{
    int val;
    int idx;
    int cnt;
    Item(int v, int i, int c) :val(v), idx(i), cnt(c){}
};

int main() {
    string seg;
    vector<int> nums;
    while(getline(cin, seg, ',')) {
        nums.push_back(stoi(seg));
    }
    // idx, cnt
    vector<Item> items{};
    // v index
    unordered_map<int, int> m;
    int n;
    for(int i=0; i<nums.size();i++) {
        n = nums[i];
        if(m.find(n) == m.end())
        {
            m[n] = items.size();
            items.emplace_back(n, items.size(), 1);
        } else {
            items[m[n]].cnt++;
        }
    }
    ::sort(items.begin(), items.end(),  [](const Item& l, const Item& r)->bool{
        if(l.cnt != r.cnt) {
            return l.cnt > r.cnt;
        }
        return l.idx < r.idx;
    });

    for(auto& item : items) {
        cout << item.val << ",";
    }
    cout << endl;
    return 0;
}