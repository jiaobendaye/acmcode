#include <iostream>
#include <string>

using namespace std;


int main() {
    string in;
    cin>>in;
    string tmp;
    for(int i=0; i<in.size(); i++) {
        if(in[i]-'0' > 4){
            tmp.push_back(in[i]-1);
        } else  {
            tmp.push_back(in[i]);
        }
    }
    // cout << tmp << endl;
    // 9进制转为10进制
    int res = 0;
    for(char c : tmp) {
        int cur = c -'0';
        res = res*9+cur;
    }
    cout << res << endl;
    return 0;
}