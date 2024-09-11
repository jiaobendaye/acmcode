#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n,0);
    for(int i=0; i<n; i++)
        cin>>vec[i];
    vector<int> ans(n, 0);
    stack<int> stk;
    for(int i=0; i<n; i++) {
        while(!stk.empty() && vec[i] > vec[stk.top()]){
            int top = stk.top();
            stk.pop();
            ans[top] = i-top;
        }
        stk.push(i);
    }

    for(int x: ans)
        cout << x << " ";
    cout << endl;
    
    return 0;
}