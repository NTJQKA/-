//P1271 �����9.��1��ѡ��ѧ����
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int main() {
    cin>>n>>m;//n����ѡ�ˣ���m��ѡƱ
    vector<int> a(n+1);
    int tmp = 0;
    while (m--) {
        cin>>tmp;
        a[tmp]++;
    }
    for (int i = 1; i <= n; ++i) {
        while (a[i]) {
            cout<<i<<" ";
            a[i]--;
        }
    }
    system("pause");
}