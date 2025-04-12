#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct bundle {
    int student_amount;
    int need;
};
bool cmp(bundle x, bundle y) {
    return x.need < y.need;
}
int main() {
    int t, n, k, m;//�������������鳤����������Ҫ����ѡ����
    cin>>t;
    while (t--) {
        cin>>n>>k;
        vector<bundle> a(n);
        for (auto &elem : a) {
            cin>>elem.student_amount;
            elem.need = k - elem.student_amount % k;
        }
        sort(a.begin(), a.end(), cmp);
        cin>>m;
        int ptr = 0;
        while (m - a[ptr].need > 0 && ptr != n) {
            m -= a[ptr].need;
            a[ptr].student_amount += a[ptr].need;
            ptr++;
        }
        long long sum = 0;
        for (auto elem : a) sum += elem.student_amount / k;
        sum += m / k;
        //���m�Ѿ����ܲ�ȫĳһ���need������ptrû��ͷ������ʡȥ�ⲽ����ѧ��֤��ʱm < a[ptr].need < k����Ȼ/kҲֻ�ܵ�0
        //�������ptr��ͷ��m����ʣ����һ�仰�Ǳ����
        cout<<sum<<endl;
    }
    system("pause");
}