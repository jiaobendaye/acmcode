#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> charsCnt(26, 0);
int wzCnt = 0;

bool isMatch(const string& word)
{
    vector<int> cnt(26,0);
    for(char c : word)
        cnt[c-'a']++;

    int diff = 0;
    for(int i=0; i<26; i++) {
        if(cnt[i] > charsCnt[i]) {
            diff +=  cnt[i] - charsCnt[i];
            if(diff > wzCnt){
                return false;
            } 
        }
    }
    return true;
}

int main() {
    int n;
    cin >>n;
    string s;
    vector<string> words(n, "");
    for(int i=0; i<n; i++)
        cin>>words[i];
    string chars;
    cin >>chars;
    for(char c : chars)
    {
        if(c == '?') {
            wzCnt++;
        } else{
            charsCnt[c-'a']++;
        }
    }
    int res = 0;
    for(auto& word :words) {
        if(isMatch(word))
            res++;
    }
    cout << res << endl;
    return 0;
}