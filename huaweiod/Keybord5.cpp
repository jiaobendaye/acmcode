#include <iostream>
#include <string>

using namespace std;

int main() {
    string in;
    getline(cin, in);
    int tot=0, selectCnt=0, clipboardCnt=0;
    for(char c : in) {
        switch (c)
        {
        case '1': { //a
            if(selectCnt>0) {
                tot -=selectCnt;
                selectCnt = 0;
            }
            tot += 1;
            break;
        }
        case '2': { //ctrl-c
            if(selectCnt>0) {
                clipboardCnt = selectCnt;
                selectCnt = 0;
            }
            break;
        }
        case '3': { //ctrl-x
            if(selectCnt>0) {
                tot -= selectCnt;
                clipboardCnt = selectCnt;
                selectCnt = 0;
            }
            break;
        }
        case '4': { // ctrl-v
            if(selectCnt>0) {
                tot -= selectCnt;
                selectCnt = 0;
            } 
            tot += clipboardCnt;
            break;
        }
        case '5': { //ctrl-a
            selectCnt = tot;
            break;
        }
        default: break;
        }
    }

    std::cout << tot << endl;

    return 0;
}