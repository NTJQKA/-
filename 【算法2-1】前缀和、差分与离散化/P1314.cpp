//P1314 [NOIP 2011 �����] �������ʼ�Ա
//ʵ���������ϸ�ںܶ࣬����ֻ�ж��ֺ�һάǰ׺�ͣ�����ǰ���漰һ�����ŽⱣ�棨���ֱ�ʽ����������Ҫ������������ǰ׺�ͣ�bool �Ƿ�ϸ�, int ��ֵ֮�ͣ���
//�ⲻ�����룬�����������еĺϸ��еĲ��ϸ�Ҳ����������Ϊ�������ɢ������ǰ׺�͡�ʵ���ϣ�ֻҪ���漰ĳ�����������ϡ�����������Ԫ�ظ�����������������Ԫ��֮�͡������ⶼ����ǰ׺�͡���򵥵İ汾����������Ԫ��ȫ������������������������
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int n, m;
i64 s, ans = 1e12;//luogu compile error with _I64_MAX
vector<int> w, v;//weight, value
vector<pair<int, int>> range;
i64 get_d(int W) {//d : s - y
    vector<int> sw(n + 1), sv(n + 1);
    for (int i = 1; i <= n; ++i) {//O(n) make table
        sw[i] = sw[i - 1], sv[i] = sv[i - 1];
        if (w[i] >= W) sw[i]++, sv[i] += v[i];
    }
    i64 y = 0;
    for (auto &p : range) {//O(m) cauculate y = sigma(y[i]), O(1)for each
        int &l = p.first, &r = p.second;
        y += (sw[r] - sw[l - 1]) * (sv[r] - sv[l - 1]);
    }
    return s - y;
}
void binary_try_y() {
    vector<int> f = w;
    sort(f.begin(), f.end());
    f.push_back(f.back() + 1);//after push_back this, y could be 0
    // w len = n + 2
    int l = 0, r = n + 1;
    while (l != r) {
        int mid = (l + r) / 2;
        i64 d = get_d(f[mid]);
        if (d == 0) {//��¼���Ŵ𰸵Ķ��֣����ֱ�ӵõ���������һ�����ŵĴ𰸿���ֱ��break
            ans = 0;
            break;
        }
        ans = min(ans, abs(d));//�߼��Ż�����¼���Ŵ𰸵Ķ��֣������Ŵ𰸵�ά��Ӧ�÷�������r������lǰ��
        if (d > 0) r = mid;
        else l = mid + 1;
    }
}
int main() {
    cin>>n>>m>>s;
    w.resize(n + 1), v.resize(n + 1), range.resize(m);
    for (int i = 1; i <= n; ++i) cin>>w[i]>>v[i];
    for (auto &elem : range) cin>>elem.first>>elem.second;
    binary_try_y();
    cout<<ans<<endl;
    system("pause");
}