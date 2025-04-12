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
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] + c;
        int target;
        auto l = lower_bound(a.begin(), a.end(), b[i]);
        auto r = upper_bound(a.begin(), a.end(), b[i]);
        ans += r - l;
        auto l = lower_bound(a.begin(), a.end(), target);
        auto r = upper_bound(a.begin(), a.end(), target);
        ans += r - l;
        //ע����ֲ��Һ�������ȫ���������ݵģ����Լ�ȡ��������upperbound�ҵ��ǵ�һ������Ŀ������Ԫ�صĵ����������������һ������Ԫ�أ����Ե��²���-1
    }
    cout<<ans<<endl;
    system("pause");
}