#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct item{
    int cost;
    int idx;
};

int main() {
    vector<item> costs;
    int i = 0;
    int c = 0;
    while(cin >>c)
    {
        costs.push_back({c, i});
        i++;
    }
    sort(costs.begin(), costs.end(), [](const item&l, const item& r)->bool{
        return l.cost > r.cost;
    });

    vector<int> out;
    for(int i=0; i<3; i++) 
        out.push_back(costs[i].idx);
    sort(out.begin(), out.end());
    for(int n :out)
        cout << n << " ";
    cout << endl;
    out.clear();

    for(int i=costs.size()-1; i>=costs.size()-3;i--)
        out.push_back(costs[i].idx);
    sort(out.begin(), out.end());
    for(int n :out)
        cout << n << " ";
    cout << endl;
    return 0;
}