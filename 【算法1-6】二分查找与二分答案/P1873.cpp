//P1873 [COCI 2011/2012 #5] EKO / 砍树
//m不会爆int，但是题里说了树的总和有可能爆int
//后续思考：可以不sort。sort后再内部二分去做是nlogn的，还不如遍历，o(n)
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
ll n, m;
bool check(vector<ll> &a, ll high) {//对二分得到的某个high值，测试能否加和大于m。其实变量名应该用height，懒得改了
    ll ans = 0;
    for (auto elem : a) {
        ll overheight = elem - high;
        if (overheight > 0) {
            ans += overheight;
        }
    }
    if (ans >= m) return true;
    else return false; 
}
int main() {
    cin>>n>>m;
    vector<ll> a(n);
    for (auto &elem : a) cin>>elem;
    sort(a.begin(), a.end());

    ll highest_tree = *(a.end() - 1);
    ll l = 0, r = highest_tree;
    while (l != r) {//目的：查合题的最大元素（查最后一个true）。已知自然数数轴是一个升序排列，答案排列应该前面全是true，后面全是false
        ll m = l + (r - l + 1) / 2;//这个+1不可以不写，试了一下，如果不写交上去是TLE，二分过程死循环了
        if (check(a, m) == true) {
            l = m;
        }
        else r = m - 1;
    }
    cout<<l<<endl;
    system("pause");
}