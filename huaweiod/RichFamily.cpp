#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct node{
    int id;
    int val;
    int sum;
};

int main() {
    int n;
    cin >>n;
    vector<node> all(n);
    for(int i=0; i<n; i++) {
        all[i].id = i;
        cin >>all[i].val;
        all[i].sum = all[i].val;
    }
    int f, s;
    for(int i=0; i<n-1; i++) {
        cin >>f >>s;
        all[f-1].sum += all[s-1].val;
    }

    sort(all.begin(), all.end(), [](const node& l, const node& r)->bool
    {
        return l.sum > r.sum;
    });
    cout << all[0].sum << endl;

    return 0;
}