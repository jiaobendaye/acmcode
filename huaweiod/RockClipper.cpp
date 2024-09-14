#include <iostream>
#include <algorithm>
#include <sstream>
 
using namespace std;
void printRes(const vector<string>& res) {
    for(auto& s : res) {
        cout << s << endl;
    }
}
int main() {
    string name, abc;
    vector<string> a, b, c;
    while(cin >>name >> abc) {
        if(abc == "A") {
            a.push_back(name);
        } else if(abc == "B") {
            b.push_back(name);
        } else {
            c.push_back(name);
        }
    }
    if(a.empty() && !b.empty() && !c.empty()){
        printRes(b);
    }
    else if(!a.empty() && !b.empty() && c.empty()){
        printRes(a);
    }
    else if(!a.empty() && b.empty() && !c.empty()){
        printRes(c);
    }
    else {
        cout << "NULL\n";
    }

    return 0;
}