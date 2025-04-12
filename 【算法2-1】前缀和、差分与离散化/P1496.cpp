//P1496 ���ճ��
//set����ȥ���ظ��˵����Զ������õģ������vector + sort + �ֶ�ȥ��Ҳ����
//map�ǰ�ÿ���˵��ֵӳ��Ϊvec�����±�or��������Ŀ����ʵ��һ��������ʡ���lower_boundÿ�������ҵõ�pos���ٽ��ж�Ӧ����Ҳ���ԣ�����ʱ�临�Ӷ�Ӧ����map������
#include <bits/stdc++.h>
using namespace std;
using iter = vector<pair<int, bool>>::iterator;
using i64 = long long;
int main() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    set<int> Set;
    vector<pair<int, bool>> Set_vec;//��˵��boolֵ������һ���Ƿ�Ⱦɫ
    Set_vec.reserve(2 * n);
    map<int, iter> Map;
    for (int i = 0; i < n; ++i) {
        cin>>a[i]>>b[i];
        Set.insert(a[i]), Set.insert(b[i]);
    }//O(n) ? ������nlogn�ġ�����һ��sizeΪn��set��ÿ��Ԫ�ض���ȡinsert�ķ������룬��֪�����Ӷ���ô�������ƽ���O(n) O(n ^ 2)֮��
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