//P3916 ͼ�ı���
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> mp;
void dfs(vector<pair<int, bool>> &ans, int node, int x) {
    if (ans[node].second == false) {//�����ڵ�Ϳɫ
        ans[node].first = x;
        ans[node].second = true;
        /*if (mp[node].size() == 0) {//�����ӽڵ���
            return;
        }*/
        //��һ�£�������Ҫ����Ϊ�����if����������Ͳ���������forѭ�����ͻ������if��Ĭ��return��
        for (int i = 0; i < mp[node].size(); ++i) {
            dfs(ans, mp[node][i], x);
        }
    }
    else return;
    //elseʱʲô��������һ��Ϊ�˱������ͼ�бջ������޵ݹ飬���Ǳ��⵹����������������
    //������Ҫ���ǵ�һ�㣬��Ϊx�������ݹ���̸ı䣬��������������forѭ��ö�ٵõ���Ҳ����˵x = x0ʱ��dfs��ͼ��ÿ������ͨ�Ľڵ㶼�ᱻ��ֵΪx�������ŵ�
}
int main() {
    cin>>n>>m;
    mp.resize(n + 1);
    while (m--) {
        int u = 0, v = 0;
        cin>>u>>v;
        mp[v].push_back(u);
    }
    vector<pair<int, bool>> ans(n + 1);
    
    //for (int i = 1; i <= n; ++i) ans[i].first = i;

    for (int i = n; i >= 1; --i) {
        dfs(ans, i, i);
    }

    for (int i = 1; i <= n; ++i) cout<<ans[i].first<<" "; cout<<endl;
    system("pause");
}