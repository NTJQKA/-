//P1157 ��ϵ����
//��ݹ�DFS��֮ͬ����ÿ��һ��whileѭ����ֻpop��һ��ջ������ȡ�������top����һЩ����֮�����ѹ��һ��ջ��Ҳ�������ϸ���Ľڵ�
//������stack��ʽģ��ʱӦ�������Ĳ���˳��ѹջ�������ǰ�֦��˳��ѹջ����ΪLIFO���ԣ���ʱ���õ���ѹջ�����籾��
//��stackģ��DFS�Ļ��������ݡ���һ���������ѣ����Ի�������ѡ�񱣴浱ǰ�ڵ��������Ϣ�ġ��ݹ鷽���У�����/����ڵ���Ϣ��ѡһ����
#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>
using namespace std;
int n, r;
stack<vector<int>> S;
int main() {
    cin>>n>>r;
    vector<int> l(n+1);
    for (int i = 0; i <= n; ++i) {
        l[i] = n - i;
    }
    //�������������Ǳ�ʾans���ѡ��iʱ�������м���ѡ��ʽ�����r - ans.size() > l[i]��ֱ�Ӽ�֦
    //д���ˣ�Ӧ����r-ans.size()-1����ΪΪ�˽�ʡ����ʱ�䣬���ʱ�������i����û�а���push��ans����
    S.push(vector<int>());
    while (!S.empty()) {
        vector<int> ans = S.top();
        S.pop();
        if (ans.size() == r) {
            for (auto elem : ans) cout<<setw(3)<<elem;
            cout<<endl;
            continue;
        }
        //bool judge;
        for (int i = n, back = ans.empty()? 0 : ans.back(); i > back; --i) {
            //cout<<ans.size()<<endl;
            //cout<<"i��ֵΪ "<<i<<", ";
            //cout<<"��ǿת"<<r - (int)(ans.size()) - 1<<" "<<l[i]<<endl;
            //cout<<r - ans.size() - 1<<" "<<l[i]<<endl;            
            //system("pause");
            if (r - ans.size() - 1 > l[i]) continue;//����ǿת����Ϊ��߱�֤�Ǹ�
            else {
                //cout<<"cheer"<<endl;
                ans.push_back(i);
                S.push(ans);
                ans.pop_back();
            }
        }
    }
    system("pause");
}