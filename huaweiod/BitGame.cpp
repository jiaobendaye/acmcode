#include <iostream>
#include <vector>
#include <bitset>

using namespace std;


int main() {
    unsigned n;
    cin >>n;
    std::string s = bitset<32>(n).to_string();
    // cout<< n<< " "<< s<< endl;
    bool flag = false;
    for(int i=s.size()-1; i>=1; i--) {
        if(s[i-1] == '0' && s[i] == '1') {
            s[i-1]='1';
            s[i] = '0';
            flag = true;
            break;
        }
    }
    if(!flag) s.push_back('0');
    unsigned m = bitset<32>(s).to_ulong();
    cout << m <<endl;
    return 0;
}