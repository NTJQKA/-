//P1271 �����9.��1��ѡ��ѧ����
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int main() {
    cin>>n>>m;//n����ѡ�ˣ���m��ѡƱ
    vector<int> a(m);
    for (auto &elem : a) cin>>elem;
    sort(a.begin(), a.end());
    for (auto elem : a) cout<<elem<<" ";
    system("pause");
}