#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
    string in;
    getline(cin, in);
    string p;
    for(char c:in) {
        if(c=='<') p.pop_back();
        else p.push_back(c);
    }
    cout << p << ',';
    if(p.length() <8){
        cout <<  "false\n"; 
        return 0;
    } 
    int a=0, A=0, n=0, o=0;
    for(char c : p) {
        if(isdigit(c)) n++;
        else if(islower(c)) a++;
        else if(isupper(c)) A++;
        else o++;
    }
    if(a*A*n*o==0) {
        cout <<  "false\n";
    } else {
        cout << "true\n"; 
    }
    return 0;
}