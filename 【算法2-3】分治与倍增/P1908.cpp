//P1908 �����
//n bound : 5 * 1e5 ; C(n, 2) bound : 124999750000
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int n;
i64 O_nsquare_solve(vector<int> &a) {
    i64 ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) ret++;
        }
    }
    return ret;
}
i64 O_nlogn_vec_solve(vector<int> &a) {//erase����O(n)���Ӷȣ����Ի���n?
//list Ҳ���У������˱��룩����Ϊ����vector��sort��lower_bound֮�󣬲�������������㣬����û����ȡԪ�ظ�����
    i64 ret = 0;
    vector<int> b = a;
    //vector<bool> vis; //�ô�����ͨ������ȡ��erase���ƿ��ԣ�ʵ����Ϊÿ��num��Ҫͳ��b������edλ��ǰ�м���false����Ȼ��Ҫo(n)�����Ա�erase��Ҫ����
    sort(b.begin(), b.end());
    for (auto &num : a) {
        auto ed = lower_bound(b.begin(), b.end(), num);
        auto op = b.begin();
        ret += ed - op;
        b.erase(ed);
    }
    return ret;
}
i64 O_nlogn_set_solve(vector<int> &a) {//�����ô�ȥ�ص�set
    i64 ret = 0;
    multiset<int> Set;
    for (auto num : a) Set.insert(num);
    for (auto &num : a) {
        auto ed = Set.lower_bound(num);
        auto op = Set.begin();
        //ret += ed - op;
        //Ҳ���У�set������Ҳ��֧����������
    }
    
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;
    //i64 ans = O_nsquare_solve(a);
    i64 ans = O_nlogn_vec_solve(a);
    cout<<ans<<endl;
    //system("pause");
}