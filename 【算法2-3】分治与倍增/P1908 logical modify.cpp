//P1908 �����
//ɾȥgoto��Ϊ������װcross��������ǰreturn��ͬʱʹ��merge��������Ҫ���ڲ�������������ӾͿ�����
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int n;
i64 cross(vector<int> &a, int l, int mid, int r) {
    i64 ret = 0;
    for (int i = mid + 1, j = l; i <= r; ++i) {
        while (a[j] <= a[i]) {
            if (j == mid) return ret;
            j++;
        }
        ret += mid - j + 1;
    }
    return ret;
}
void merge(vector<int> &a, int l, int mid, int r) {
    vector<int> tmp(r - l + 1);
    int i = l, j = mid + 1;//���������������ʼָ��
    for (int k = 0; k < tmp.size(); ++k) {
        if (i == mid + 1) tmp[k] = a[j++];//ע��������Ҫָ��Խ�磬��a.end()��ָ�����һ��λ���ǲ����Եģ�����jͬ��
        else if (j == r + 1) tmp[k] = a[i++];
        else a[i] <= a[j] ? tmp[k] = a[i++] : tmp[k] = a[j++];
    }
    for (auto elem : tmp) a[l++] = elem;
}
i64 solve(vector<int> &a, int l, int r) {
    if (l == r) return 0;
    int mid = l + (r - l) / 2;
    i64 ret = solve(a, l, mid) + solve(a, mid + 1, r) + cross(a, l, mid, r);
    merge(a, l, mid, r);
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;
    i64 ans = solve(a, 0, n - 1);
    cout<<ans<<endl;
    system("pause");
}