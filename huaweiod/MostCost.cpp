#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> in;
    while(getline(iss, line, ',')){
        in.push_back(stoi(line));
    }
    
    int target;
    cin >> target;

    if(in.size() < 3) {
        cout << "bad case\n";
        return 0;
    }
    sort(in.begin(), in.end());
    // for(int x:in)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    int ans = 0;
    for(int i=0; i<in.size(); i++)
    {
        int left = i+1, right = in.size()-1;
        while(left < right)
        {
            int cost = in[i]+in[left]+in[right];
            if(cost  <= target) {
                ans =max(ans, cost);
                left++;
            } else {
                right--;
            }
        }
    }

    cout << ans<<endl;
    return 0;
}