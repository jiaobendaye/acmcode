#include <iostream>
#include <vector>
using namespace std;

// m个人，n个月饼，每个人至少low个的分法个数
int assign(int m, int n, int low) {
    if(m <0 || n < 0 || m*low>n) return 0;
    if(m == 0 && n==0) return 1;
    int cnt =0;
    int up = min(low+3, n);
    for(int i=0; i<=up;i++)
    {
        cnt += assign(m-1, n-i, i);
    }
    return cnt;
}

int main() {
    int m, n;
    cin >>m >>n;
    int ans = 0;
    int left = n-m;
    for(int i=0; i<=left; i++){
        ans += assign(m-1, left-i, i);
    }
    cout << ans << endl;
    return 0;
}