#include <iostream>
#include <deque>
#include <unordered_set>

using namespace std;
int main() {
    int n;
    cin >>n;
    int f;
    unordered_set<int> playing, waiting, unhappy;
    deque<int> waitQ;

    while(cin>>f) {
        if(playing.count(f)) // 完后要离开
        {
            playing.erase(f);
            while(!waitQ.empty())
            {
                int w = waitQ.front();
                waitQ.pop_front();
                if(waiting.count(w)) //还在等待中
                {
                    playing.insert(w);
                    waiting.erase(w);
                    break;
                }
            }
        } else if(waiting.count(f)) //不等了
        {
            unhappy.insert(f);
            waiting.erase(f);
        } else { //新来的
            if(playing.size() < n)
            {
                playing.insert(f);
            } else {
                waiting.insert(f);
                waitQ.push_back(f);
            }
        }
    }

    cout << unhappy.size() << endl;
    return 0;
}