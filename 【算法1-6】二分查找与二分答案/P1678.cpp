//P1678 烦恼的高考志愿
//注意看输出结果，有灵异事件，前面mid还是0的时候，出了while循环就不知道为什么变成一个大数，而mid是外界变量，应该能得到继承的……
//所以还是老老实实初始化吧，没准编译器都有bug
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define scan1(a) for (auto &elem : a) cin>>elem;
#define p1(num) cout<<num<<" ";
#define p2(num) cout<<num<<endl;
#define p3(arr) for (auto elem : arr) cout<<elem<<" "; cout<<endl;
int m, n;
long long ans;
int judge_pos(vector<int> &a, int x) {
    int l = 0, r = m-1, mid = 0;
    while (l != r) {
        int mid = l + (r - l) / 2;
        if (x >= a[mid] && x < a[mid+1]) return mid;
        else if (x < a[mid]) r = mid;
        else l = mid + 1;
    }
    return l;
}
int main() {
    cin>>m>>n;
    vector<int> a(m), b(n);
    scan1(a) scan1(b)

    sort(a.begin(), a.end());
    
    for (auto elem : b) {
        int pos = judge_pos(a, elem);
        if (pos == 0 && elem < a[pos]) ans += fabs(elem - a[0]);
        else if (pos == m-1) ans += fabs(elem - a[m-1]);
        else {
            int d1 = fabs(elem - a[pos]), d2 = fabs(elem - a[pos+1]);
            d1 < d2 ? ans += d1 : ans += d2;
        }
    }

    cout<<ans<<endl;
    system("pause");
}