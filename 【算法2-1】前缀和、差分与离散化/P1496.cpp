//P1496 火烧赤壁
//set用来去掉重复端点且自动排序用的，如果想vector + sort + 手动去重也可以
//map是把每个端点的值映射为vec数组下标or迭代器，目的是实现一个反向访问。用lower_bound每次做查找得到pos，再进行对应操作也可以，但是时间复杂度应该是map更优秀
#include <bits/stdc++.h>
using namespace std;
using iter = vector<pair<int, bool>>::iterator;
using i64 = long long;
int main() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    set<int> Set;
    vector<pair<int, bool>> Set_vec;//左端点的bool值代表这一段是否被染色
    Set_vec.reserve(2 * n);
    map<int, iter> Map;
    for (int i = 0; i < n; ++i) {
        cin>>a[i]>>b[i];
        Set.insert(a[i]), Set.insert(b[i]);
    }//O(n) ? 可能是nlogn的。构建一个size为n的set，每个元素都采取insert的方法插入，不知道复杂度怎么样，估计介于O(n) O(n ^ 2)之间
    for (auto &elem : Set) {
        Set_vec.push_back({elem, false});
    }//O(n)
    for (auto i = Set_vec.begin(); i != Set_vec.end(); ++i) {
        auto &elem = (*i).first;
        Map[elem] = i;
    }//O(n)
    for (int i = 0; i < n; ++i) {
        iter op = Map[a[i]], ed = Map[b[i]];
        for (auto j = op; j != ed; ++j) {
            (*j).second = true;
        }
    }//O(n ^ 2) worst situation
    i64 ans = 0;
    for (auto i = Set_vec.begin(); i != Set_vec.end() - 1; ++i) {
        if ((*i).second) {
            int op = (*i).first, ed = (*(i + 1)).first;
            ans += ed - op;
        }
    }//O(n)
    cout<<ans<<endl;
    system("pause");
}