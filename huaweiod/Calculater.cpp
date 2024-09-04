#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
long gcd(long a, long b) {
    if(a < b) return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a%b);
}

class Frac{
private:
    long fz;
    long fm;
public:
    Frac(int z, int m):fz(z), fm(m) {}

public:
    string toString() const {
        if(fm ==1) {
            return to_string(fz);
        } else {
            string rs = to_string(abs(fz)) +"/" + to_string(abs(fm));
            if(fz *fm <0) rs = "-" + rs;
            return rs;
        }
    }

    Frac simplify() const {
        long gcd_v = gcd(abs(fz), abs(fm));
        return Frac(fz/gcd_v, fm/gcd_v);
    }

public:
    Frac add(const Frac& otr) {
        long nfz = this->fz*otr.fm + this->fm*otr.fz;
        long nfm = this->fm * otr.fm;
        return Frac(nfz, nfm).simplify();
    }

    Frac sub(const Frac& otr) {
        long nfz = this->fz*otr.fm - this->fm*otr.fz;
        long nfm = this->fm * otr.fm;
        return Frac(nfz, nfm).simplify();
    }

    Frac mul(const Frac& otr) {
        long nfz = this->fz*otr.fz;
        long nfm = this->fm * otr.fm;
        return Frac(nfz, nfm).simplify();
    }

    Frac div(const Frac& otr) {
        if(otr.fz == 0) throw runtime_error("ERROR");

        long nfz = this->fz*otr.fm;
        long nfm = this->fm * otr.fz;
        return Frac(nfz, nfm).simplify();
    }
};

class Solution{
public:

    Solution() { }

    Frac calculate(const string& s) {
        int n= s.size();
        nums.push(Frac(0,1));
        for(int i=0; i<n; i++) {
            char c = s[i];
            if(c == '('){
                ops.push(c);
            } else if(c == ')') {
                while(!ops.empty()) {
                    if(ops.top() != '(') {
                        this->calc();
                    } else {
                        ops.pop();
                        break;
                    }
                }
            } else {
                if(isdigit(c)) {
                    int cur_num = 0;
                    int j = i;
                    // 将从 i 位置开始后面的连续数字整体取出，加入 nums
                    while(j <n && isdigit(s[j]))
                        cur_num = cur_num*10 + (s[j++] - '0');
                    nums.push(Frac(cur_num, 1));
                    i = j-1;
                } else {
                    if (i > 0 && (s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-')) {
                        nums.push(Frac(0, 1));
                    }
                    while (!ops.empty() && ops.top() != '(') {
                        char prev = ops.top();
                        if (m[prev] >= m[c]) {
                            calc();
                        } else {
                            break;
                        }
                    }
                    ops.push(c);
                }
            }
        }

        while(!ops.empty()) this->calc();
        return nums.top();
    }
private:
    void calc() {
        if(nums.size() < 2 || ops.empty()) return;
        Frac b = nums.top(); nums.pop();
        Frac a = nums.top(); nums.pop();
        char c = ops.top(); ops.pop();
        switch (c)
        {
        case '+':{ nums.push(a.add(b)); break;}
        case '-':{ nums.push(a.sub(b)); break;}
        case '*':{ nums.push(a.mul(b)); break;}
        case '/':{ nums.push(a.div(b));break;}
        default:
            break;
        }
    }

private:
    stack<Frac> nums;
    stack<char> ops;
    unordered_map<char, int> m = {{'-',1}, {'+',1}, {'*',2}, {'/',2}};
};

int main() {
    string in;
    getline(cin, in);
    in.erase(remove_if(in.begin(), in.end(), ::isspace), in.end());
    // cout << in << endl;
    try
    {
        Solution sol;
        auto res = sol.calculate(in);
        cout << res.toString() << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}