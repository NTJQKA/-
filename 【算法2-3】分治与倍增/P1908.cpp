//P1908 逆序对
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
i64 O_nlogn_vec_solve(vector<int> &a) {//erase带来O(n)复杂度，所以还是n?
//list 也不行（过不了编译），因为仿照vector做sort和lower_bound之后，不允许迭代器运算，所以没法获取元素个数差
    i64 ret = 0;
    vector<int> b = a;
    //vector<bool> vis; //用处不大，通过打标记取代erase看似可以，实则因为每个num都要统计b数组中ed位置前有几个false，仍然需要o(n)，所以比erase还要慢点
    sort(b.begin(), b.end());
    for (auto &num : a) {
        auto ed = lower_bound(b.begin(), b.end(), num);
        auto op = b.begin();
        ret += ed - op;
        b.erase(ed);
    }
    return ret;
}
i64 O_nlogn_set_solve(vector<int> &a) {//不能用带去重的set
    i64 ret = 0;
    multiset<int> Set;
    for (auto num : a) Set.insert(num);
    for (auto &num : a) {
        auto ed = Set.lower_bound(num);
        auto op = Set.begin();
        //ret += ed - op;
        //也不行，set迭代器也不支持四则运算
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