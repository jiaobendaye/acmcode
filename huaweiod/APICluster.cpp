#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


int main() {
    //level,  name  cnt
    unordered_map<int, unordered_map<string, int>> data;
    int n ;
    // cin >>n;
    string line;
    getline(cin, line);
    n = stoi(line);
    for(int i=0; i<n; i++) {
        getline(cin, line);
        istringstream iss(line);
        int l = 1;
        while(getline(iss, line, '/')) {
            if(line.empty() || line[0] == ' ')continue;
            data[l][line]++;
            l++;
        }
        cout << endl;
    }
    int level;
    cin >> level >> line;
    cout << data[level][line] << endl;
    return 0;
}