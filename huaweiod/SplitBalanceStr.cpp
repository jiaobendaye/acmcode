#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin>>input;
    char C = input[0];
    int w=0, cnt=0;
    int res;
    for(int i=0; i<input.size(); i++) {
        w++;
        if(C==input[i]) cnt++;
        if(cnt >0 && (2*cnt) == w) {
            res++;
            w=0;
            cnt=0;
        }
    }
    cout << res << endl;
    return 0;
}