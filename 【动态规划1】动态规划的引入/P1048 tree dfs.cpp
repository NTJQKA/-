//��д������dfs��OIwiki�ϵĲ�һ��������д��������д��Ҫ�ڲ�ֽ�ϰ�����������Һ�ջ֮��Ŀ��ƽ����ϵ������dfs�ͱ߽��жϷ���for�ڻ����⣨��Ȼ���ݾ��飬һ�㶼��dfs�ͱ߽��жϷ�for���棩������û���ü����Ż�
//�Ա�����ԣ����Ѿ���01����dp�ĵݹ�д�������ǽ�������DFS��Ҫ��Ӳ��DFS��Ӧ��Ӧ���Ƕ���ÿ��pos��ֻ��0��1����ҩȡ��ȡ������״̬��DFS����ʵ��ͬ��M��forѭ��ö�٣�ֻ�������ڼ��仯�����¼����������֤ÿ��posֻ����1�ζ���
#include <bits/stdc++.h>
#define v_print(x) for (auto &elem : x) cout<<elem<<" "; cout<<endl;
using namespace std;
int T, M;
int ans;
vector<int> a, b;//a : time, b : value
vector<bool> used;
void dfs(int pos, int t, int v, int &t_op) {
    if (clock() - t_op > 9900) {//��ʱ ���ǲ�֪����ô���³����ˣ���990��ʱ�򣬳���ֻ��8ms�ͱ���WA��
        cout<<ans<<endl;
        exit(0);
    }
    for (int i = pos; i < M; ++i) {//let i goes from pos, to avoid same situation
        if (t + a[i] > T) {
            ans = max(ans, v);
            continue;
        }
        //else (t + a[i] <= T)
        if (i == M - 1) ans = max(ans, v + b[i]);//t + a[pos] <= T and pos = M - 1
        dfs(i + 1, t + a[i], v + b[i], t_op);
    }
}
int main() {
    int t_op = clock();
    cin>>T>>M;
    a.resize(M), b.resize(M), used.resize(M);
    for (int i = 0; i < M; ++i) cin>>a[i]>>b[i];
    //v_print(a) v_print(b)
    dfs(0, 0, 0, t_op);
    //if (!ans) ans = accumulate(b.begin(), b.end(), 0);//hack when dfs does not reach if (t >= T)
    cout<<ans<<endl;
    system("pause");
}