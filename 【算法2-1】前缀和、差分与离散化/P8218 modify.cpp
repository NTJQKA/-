//P8218 �����1.��1���������
//�漰ǰ׺��ʱ��an��sn������ö�����n + 1�ģ��������������ʱ���ÿ���l - 1�±�Ϊ0Խ�����⣬�����ӱ߽��жϵ�ʹ��A[r] - A[l - 1]��ʽ
#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    cin>>n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    vector<int> A(n + 1);
    partial_sum(a.begin(), a.end(), A.begin());
    cin>>m;
    while (m--) {
        int l = 0, r = 0; cin>>l>>r;
        cout<<A[r] - A[l - 1]<<endl;
    }
}