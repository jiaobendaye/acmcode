#include <queue>
#include <iostream>

using namespace std;

struct  Node
{
    long weight = 0;
    int height = 1;
    Node* left =nullptr;
    Node* right =nullptr;

    Node(int w, Node* l=nullptr, Node* r=nullptr):weight(w), left(l), right(r) {}

    bool operator<(const Node& othr) const {
        if(weight != othr.weight) {
            return weight > othr.weight;
        }

        return height > othr.height;
    }
};

void inorder(Node* root) {
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->weight << " ";
    inorder(root->right);
}

int main() {
    int n;
    cin >>n;
    priority_queue<Node> minHeap;
    int a;
    for(int i=0; i<n; i++) {
        cin>>a;
        minHeap.push({a});
    }
    while(minHeap.size() >1) {
        Node left = minHeap.top(); minHeap.pop();
        Node right = minHeap.top(); minHeap.pop();

        int sum = left.weight+right.weight;
        Node p(sum);
        p.height = max(left.height, right.height) +1;
        p.left = new Node(left.weight, left.left, left.right);
        p.right = new Node(right.weight, right.left, right.right);
        minHeap.push(p);
    }
    Node root = minHeap.top();
    inorder(&root);
    cout << endl;
    return 0;
} 