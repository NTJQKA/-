//P3817 小A的糖果
//思维不全面。没考虑第一个盒子糖就超标的情形。这个其一靠严谨性训练，其二靠随机数据生成/对拍，前者很难，所以有空至少要学一下造数据的本领
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