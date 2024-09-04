#include <iostream>

using namespace std;

class Node{
public:
    Node* left;
    Node* mid;
    Node* right;
    int val;

    Node(int v) : val(v), left(nullptr), mid(nullptr), right(nullptr) {}

    ~Node() {
        if(left){
            delete left;
            left =nullptr;
        } 
        if(mid){
            delete mid;
            mid =nullptr;
        } 
        if(right){
            delete right;
            right =nullptr;
        } 
    }

    void insert(int v) {
        if(v < (val - 500)) {
            if(this->left) {
                return left->insert(v);
            }
            this->left = new Node(v);
        } else if(v >(val + 500)) {
            if(this->right) {
                return right->insert(v);
            }
            this->right = new Node(v);
        } else {
            if(this->mid) {
                return mid->insert(v);
            }
            this->mid = new Node(v);
        }
    }

    int height() {
        int maxHeight = 0;
        if(left) maxHeight = max(maxHeight, left->height());
        if(mid) maxHeight = max(maxHeight, mid->height());
        if(right) maxHeight = max(maxHeight, right->height());
        return maxHeight+1;
    }
};

int main() {
    int n, v;
    cin >> n >> v;
    Node* root = new Node(v);
    for(int i=1; i<n; i++) {
        cin >>v;
        root->insert(v);
    }
    cout << root->height() << endl;

    return 0;
}