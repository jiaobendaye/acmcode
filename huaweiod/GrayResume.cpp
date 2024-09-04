
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


int main() {
    vector<int> inputs;
    int a;
    while(cin >>a) inputs.push_back(a);
    int n= inputs.size();
    int x = inputs[n-2], y = inputs[n-1];
    int col = inputs[1];
    int pos = x * col + y +1;
    for(int i=3, sum =0; i< n-1; i+=2) {
        if(sum + inputs[i]>=pos) {
            cout << inputs[i-1] << endl;
            break;
        }
        sum += inputs[i];
    }

    return 0;
}