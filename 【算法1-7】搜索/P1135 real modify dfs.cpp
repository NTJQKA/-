//P1135 ��ֵĵ���
//��Ȼ�����⻹��һ��������yummy��С��˵�����ģ���������ʱ���֦������������н���1s��������������������޽��ˣ�����ֱ��kill��Ȼ��cout<<-1
//��Ȼ������а���������Ҳ²������ô���Ļ����ò�һ����Ǹ��������Ƚϵļ�֦Ҳ�ܽ���100�֣����ܻ��ǻᱻhackһ������
//�пձ���ѧϰһ�����ַ�������Ȼû���κ�ָ�����壬�������л��������Լ��ھ����еķ�����ʹ��������������TLEʱ�������MLE�ͱ����ˣ�һ���ǽڵ������ˣ����ݹ飬��ջ
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;
int n, from, to;
int his_cnt = INT_MAX;
void dfs(vector<int> &a, vector<int> &b, int pos, int cnt) {
    if (cnt < b[pos]) b[pos] = cnt;
    else return;
    //����ÿһ��������ֻ��һ������Ƚϵļ�֦��
    //for (auto elem : b) cout<<elem<<" "; cout<<endl;
    if (pos == to) {
        his_cnt = cnt;
        return;
    }
    else {
        if (pos + a[pos] >= 0 && pos + a[pos] < n) {
            dfs(a, b, pos + a[pos], cnt+1);
            //cout<<"retreat : "; for (auto elem : b) cout<<elem<<" "; cout<<endl;
        }
        if (pos - a[pos] >= 0 && pos - a[pos] < n) {
            dfs(a, b, pos - a[pos], cnt+1);
            //cout<<"retreat : "; for (auto elem : b) cout<<elem<<" "; cout<<endl;
        }
    }
    return;
}
int main() {
    cin>>n>>from>>to;
    from--, to--;//���ݳ�ʼ��
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;
    vector<int> b(n);//��ǵ���ÿһ������Ҫ����С�����������Ϊ�����Ķ���history_cnt(min)��yummy�����˵�˼·
    for (auto &elem : b) elem = INT_MAX;
    dfs(a, b, from, 0);
    his_cnt == INT_MAX ? cout<<-1<<endl : cout<<his_cnt<<endl;
    system("pause");
}