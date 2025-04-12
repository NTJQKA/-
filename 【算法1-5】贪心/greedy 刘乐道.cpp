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
    int t, n, k, m;//数据组数，数组长，比例，需要安排选手数
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
        //如果m已经不能补全某一组的need，但是ptr没到头，可以省去这步，数学可证此时m < a[ptr].need < k，显然/k也只能得0
        //但是如果ptr到头了m还有剩，这一句话是必须的
        cout<<sum<<endl;
    }
    system("pause");
}