//�����ܵڶ���������һ���ӣ�֤ʵ�˴���ȷ������ʱ�����˽���3.5min
//�����ԭʼʱ�临�Ӷ���nlogn + 2nlogn����������̫���ˣ�
//Ҫô����STL lowerbound upperbound�Ż���Ҫô�������ݴ���������ָ��ά�������Ƕ��֣����o(nlogn + n)
//STL���ֺ������˲��1s���ѵ��ҵĶ��ֺ����ٶȺ���������
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int n, c;
ll ans;
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>c;
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;
    sort(a.begin(), a.end());
    vector<int> b(n);
    int l = 0, r = 0;//ע���ʼ����for���棬��Ҳ��ָ��ά���ľ���
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] + c;
        while (l < n && a[l] < b[i]) l++;
        while (r < n && a[r] <= b[i]) r++;
        ans += r - l;
    }
    cout<<ans<<endl;
    system("pause");
}