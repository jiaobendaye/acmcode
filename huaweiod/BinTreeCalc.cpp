#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>

using namespace std;

vector<int> res;

void helper(vector<int>& inorder, vector<int>& preorder) {
    if(inorder.empty() || preorder.empty()) return;
    int root = preorder[0];
    auto pos = find(inorder.begin(), inorder.end(), root);
    int idx = distance(inorder.begin(), pos);

    vector<int> leftInorder(inorder.begin(), inorder.begin()+idx);
    vector<int> rightInorder(inorder.begin()+idx+1, inorder.end());

    vector<int> leftPreorder(preorder.begin()+1, preorder.begin()+idx+1);
    vector<int> rightPreorder(preorder.begin()+idx+1, preorder.end());

    helper(leftInorder, leftPreorder);
    int leftSum = accumulate(leftInorder.begin(), leftInorder.end(), 0);
    int rightSum = accumulate(rightInorder.begin(), rightInorder.end(), 0);

    res.push_back(leftSum + rightSum);
    helper(rightInorder, rightPreorder);
}

int main() {
    string line;
    string seg;
    vector<int> inorder;
    getline(cin, line);
    istringstream iss(line);
    while(getline(iss, seg, ' ')) inorder.push_back(stoi(seg));

    vector<int> preorder;
    getline(cin, line);
    istringstream iss2(line);
    while(getline(iss2, seg, ' ')) preorder.push_back(stoi(seg));
    helper(inorder, preorder);
    for(int x: res)
        cout << x << " ";
    cout << endl;
    return 0;
}