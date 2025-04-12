//P1827 [USACO3.4] ����Ѫͳ American Heritage
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
string pre, in;
map<char, int> Map;
map<char, pair<char, char>> tree;
void BuildTree(int l1, int r1, int l2, int r2) {//����ҿ�
    char root = pre[l1++];//�Ȼ�ȡ����Ȼ��Ѹ�ٰ�ָ������һλ�������ں���д�±�����ʱ���࣬ʹ�õ� +1 -1 ����
    if (l1 == r1) return;//���Ҿ����ӽڵ�
    int mid2 = Map[root];
    int mid1 = l1 + mid2 - l2;
    if (l1 != mid1) {//��������
        tree[root].first = pre[l1];
        BuildTree(l1, mid1, l2, mid2);
    }
    if (mid1 != r1) {//��������
        tree[root].second = pre[mid1];
        BuildTree(mid1, r1, mid2 + 1, r2);
    }
}
void solve(char ch) {//�����������ӡ
    if (ch == '\0') return;
    solve(tree[ch].first);
    solve(tree[ch].second);
    cout<<ch;
}
int main() {
    cin>>in>>pre;
    for (int i = 0; i < in.length(); i++) Map[in[i]] = i;
    BuildTree(0, pre.length(), 0, in.length());
    solve(pre[0]);
    //system("pause");
}