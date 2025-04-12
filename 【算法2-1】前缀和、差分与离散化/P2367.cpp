//P2367 ���ĳɼ�
//ע�⣺min_elementʱ��Ҫ����Ԥ����a[0]����������ʹ��begin()+1����Ϊa[0]һ����0
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#define debug(x) for (auto &elem : x) cout<<elem<<" "; cout<<endl;
using namespace std;
int n, p;
int main() {
    cin>>n>>p;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    vector<int> d(n + 1);
    //for (int i = 1; i <= n; ++i) d[i] = a[i] - a[i - 1];
    adjacent_difference(a.begin(), a.end(), d.begin());
    //debug(a) debug(d)
    while (p--) {
        int x, y, z; cin>>x>>y>>z;
        d[x] += z;
        if (y + 1 <= n) d[y + 1] -= z;
    }
    //for (auto &elem : a) elem = 0;
    partial_sum(d.begin(), d.end(), a.begin());
    //cout<<"---------------"<<endl;
    //debug(a) debug(d)
    cout<<*min_element(a.begin() + 1, a.end())<<endl;
    system("pause");
}