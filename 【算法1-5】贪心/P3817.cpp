//P3817 СA���ǹ�
//˼ά��ȫ�档û���ǵ�һ�������Ǿͳ�������Ρ������һ���Ͻ���ѵ��������������������/���ģ�ǰ�ߺ��ѣ������п�����Ҫѧһ�������ݵı���
#include <iostream>
#include <vector>
using namespace std;
#define p1(num) cout<<num<<" ";
#define p2(num) cout<<num<<endl;
#define p3(arr) for (auto elem : arr) cout<<elem<<" "; cout<<endl;
#define p4(mat) for (auto row : mat) {for (auto elem : row) cout<<elem<<" "; cout<<endl;}
#define ll long long
int n, x;
ll ans;
int main() {
    cin>>n; cin>>x;
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;
    if (a[0] > x) {
        ans += a[0] - x;
        a[0] = x;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] + a[i+1] > x) {
            int d = a[i] + a[i+1] - x;
            a[i+1] -= d;
            ans += d;
            //p3(a)
        }
    }
    cout<<ans<<endl;
    system("pause");
}