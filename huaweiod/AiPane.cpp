#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int id;
    int x1, y1, x2, y2;
};

//高度
bool cmpY(const Node& l, const Node& r)
{
    return l.y1 < r.y1;
}

bool cmpX(const Node& l, const Node& r)
{
    return l.x1 < r.x1;
}

int main() {
    int n;
    cin >>n;
    vector<Node> nodes(n);
    for(int i=0; i<n; i++) {
        auto& node = nodes[i];
        cin >> node.id >> node.x1 >> node.y1 >> node.x2 >>node.y2;
    }

    sort(nodes.begin(), nodes.end(), cmpY);
    int l = 0;
    for(int i=1; i<nodes.size(); i++)
    {
        if(nodes[i].y1 - nodes[l].y1 <= (nodes[l].y2-nodes[l].y1)/2) continue;
        sort(nodes.begin()+l, nodes.begin()+i, cmpX);
        l = i;
    }
    sort(nodes.begin()+l, nodes.end(), cmpX);

    for(auto& node: nodes) {
        cout << node.id << " ";
    }
    cout << endl;

    return 0;
}