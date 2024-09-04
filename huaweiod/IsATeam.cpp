#include <iostream>
#include <vector>
#include <string>
using namespace std;


int maxN = 100001;
vector<int> parent(maxN, 0);

int find(int x)
{
    if(parent[x] == 0) {
        parent[x] = x;
    }
    if(parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void insert(int x, int y)
{
    int xRoot = find(x);
    int yRoot = find(y);
    if(xRoot == yRoot) return;
    parent[xRoot] = yRoot;
}

int main() {
    int n, m;
    cin >>n >>m;
    int a, b, c;
    for(int i=0; i<m; i++)
    {
        cin>>a >>b >>c;
        if(a ==0 || a>= maxN || b==0 || b>=maxN) {
            cout << "da pian zi\n";
            continue;
        }
        if(c == 0) {
            insert(a, b);
        } else if(c==1) {
            if(find(a) == find(b)) {
                cout << "we are a team\n";
            } else {
                cout << "we are not a team\n";
            }
        } else {
            cout << "da pian zi\n";
        }
    }

    return 0;
}