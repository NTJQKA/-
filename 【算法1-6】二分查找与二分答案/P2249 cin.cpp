//P2249 ¡¾Éî»ù13.Àı1¡¿²éÕÒ
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n, m;
inline int find(vector<int> &a, int target) {
    int l = 0, r = n - 1;
    while (l != r) {
        int m = (l + r) / 2;
        if (a[m] >= target) r = m;
        else l = m + 1;
    }
    if (a[l] == target) return l + 1;
    else return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;
    int target = 0;
    while (m--) {
        cin>>target;
        cout<<find(a, target)<<" ";
    }
    //system("pause");
}