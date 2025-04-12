//P2440 木材加工
//o(nlogL)
#include <iostream>
#include <vector>
using namespace std;
int n, k;//树的棵数，期望获得段数
bool judge(vector<int> &a, int d) {//想切长为d的小段
    int ans = 0;
    for (auto elem : a) ans += elem / d;
    if (ans >= k) return true;
    else return false;
}
int main() {
    cin>>n>>k;
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;

    int l = 0, r = 1e8;
    while (l != r) {
        int mid = l + (r - l + 1) / 2;
        if (judge(a, mid)) l = mid;
        else r = mid - 1;
    }
    cout<<l<<endl;
    system("pause");
}