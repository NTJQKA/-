//P2249 �����13.��1������
//����д����һ������3ms
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;
    int target = 0;
    while (m--) {
        cin>>target;
        auto iter = lower_bound(a.begin(), a.end(), target);
        int pos = iter - a.begin();
        if (pos == n || target != a[pos]) cout<<-1<<" ";
        else cout<<pos + 1<<" ";//+1����Ϊ����Ҫ���±��1��ʼ���
    }
    system("pause");
}