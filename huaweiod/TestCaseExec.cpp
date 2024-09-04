#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct Case {
    int id;
    int sum;
};

int main() {
    int N, M;
    cin >>N >>M;
    vector<int> prios(N+1,0);
    for(int i=1; i<=N; i++)
        cin>>prios[i];

    cin.ignore(); //清除缓冲区的\n
    vector<Case> cases(M);
    string line;
    for(int i=0; i<M; i++) {
        getline(cin, line);
        istringstream iss(line);
        cases[i].id = i+1;
        string seg;
        cout << endl;
        while(getline(iss, seg, ' ')) {
            cases[i].sum += prios[stoi(seg)];
        }
    }
    sort(cases.begin(), cases.end(), [](const Case& l, const Case&r){
        if(l.sum != r.sum) {
            return l.sum>r.sum;
        }
        return l.id < r.id;
    });
    for(auto& c : cases) {
        cout << c.id << endl;
    }
    return 0;
}