//P1678 ���յĸ߿�־Ը
//������һ�棬1ms����ɼ�lower_bound�����ú���
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define scan1(a) for (auto &elem : a) cin>>elem;

int m, n;
long long ans;

int main() {
    cin>>m>>n;
    vector<int> a(m), b(n);
    scan1(a) scan1(b)

    sort(a.begin(), a.end());
    
    for (auto elem : b) {
        auto iter = lower_bound(a.begin(), a.end(), elem);
        int pos = iter - a.begin();//������ת�±�Ŀ�����ֲ����
        if (pos == 0) ans += fabs(elem - a[0]);
        else if (pos == m) ans += fabs(elem - a[m-1]);
        else {
            int d1 = fabs(elem - a[pos-1]), d2 = fabs(elem - a[pos]);
            d1 < d2 ? ans += d1 : ans += d2;
        }
    }

    cout<<ans<<endl;
    system("pause");
}