//�����ܵڶ���������һ���ӣ�֤ʵ�˴���ȷ������ʱ�����˽���3.5min
//ѯ��deepseek�����������ʱ���������������ʽ����д�ֵ�����紫����Ϊn�����飬�ڴ�ֵ�Ͽ�������o(n)�����ǲ��ܽ��ܵġ��������Ǵ�һ��ָ�룬o(1)
//���⣬������ͨ��inline��������������һ�������������飡����STL���ڹ涨��ʵ�ַ�ʽ����һ�������ģ���cin.tie(nullptr)�ȷ�ʽ��һ������
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int n, c;
ll ans;
inline int find(vector<int> &a, int target, int l, int r) {
    while (l != r) {
        int m = l + (r - l) / 2;
        if (a[m] >= target) r = m;
        else l = m + 1;
    }
    if (a[l] == target) return l;
    else return -1;
}
inline int rfind(vector<int> &a, int target, int l, int r) {
    while (l != r) {
        int m = l + (r - l + 1) / 2;
        if (a[m] <= target) l = m;
        else r = m - 1;
    }
    if (a[l] == target) return l;
    else return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>c;
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;
    sort(a.begin(), a.end());
    vector<int> b(n);
    for (auto elem : a) {
        int target = elem + c;
        int flag = find(a, target, 0, n-1);
        if (flag != -1) {
            int last = rfind(a, target, flag, n-1);
            ans += last - flag + 1;
        }//���Ҫ�Ż��Ļ�������lower_bound upper_bound���ּ��ݷ�ʽ�����������Ļ����޷���.end()�����ü��߼��жϣ���ʡ�����߼�����ʱ��
    }
    cout<<ans<<endl;
    system("pause");
}