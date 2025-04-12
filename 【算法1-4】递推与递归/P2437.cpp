#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int c_t_i(char ch) {
    return ch - '0';
}
char i_t_c(int x) {
    return (char)(x + '0');
}
string hiplus(string a, string b) {
    int need_zero_amount = fabs((int)a.length() - (int)b.length());
    string zero_str(need_zero_amount, '0');
    a.length() < b.length() ? a = zero_str + a : b = zero_str + b;
    string ans;
    int carry = 0;
    for (int i = a.length()-1; i >= 0; --i) {
        int tmp = c_t_i(a[i]) + c_t_i(b[i]) + carry;
        tmp >= 10 ? carry = 1 : carry = 0;
        char ch = i_t_c(tmp % 10);
        ans = ch + ans;
    }
    if (carry) ans = '1' + ans;
    return ans;
}
int main() {
    int n, m;
    cin>>n>>m;
    const int tot = m - n + 1;
    vector<string> a(tot);
    a[0] = "1", a[1] = "1";
    for (int i = 2; i < tot; ++i) {
        a[i] = hiplus(a[i-1], a[i-2]);
    }
    cout<<a[tot-1]<<endl;
    system("pause");
}