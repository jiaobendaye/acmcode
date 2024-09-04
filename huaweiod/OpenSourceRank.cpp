#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >>n;
    vector<int> weis(5, 0);
    for(int i=0; i<5; i++)
        cin>>weis[i];

    // hot, name
    vector<pair<int, string>> projects(n);

    for(int i=0; i<n; i++) {
        auto& p = projects[i];
        string name;
        cin >>p.second;
        vector<int> v(5,0);
        for(int i=0; i<5; i++)
            cin>>v[i];
        for(int i=0; i<5; i++)
            p.first += v[i]*weis[i];
        for(char& c :p.second) {
            c=tolower(c);
        }
    }

    sort(projects.begin(), projects.end(), [](const auto& l, const auto& r){
        if(l.first != r.first) {
            return l.first > r.first;
        }
        return l.second < r.second;
    });
    for(auto& p : projects)
        cout << p.second << endl;
    return 0;
}