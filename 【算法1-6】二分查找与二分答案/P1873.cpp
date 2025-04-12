//P1873 [COCI 2011/2012 #5] EKO / ����
//m���ᱬint����������˵�������ܺ��п��ܱ�int
//����˼�������Բ�sort��sort�����ڲ�����ȥ����nlogn�ģ������������o(n)
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
ll n, m;
bool check(vector<ll> &a, ll high) {//�Զ��ֵõ���ĳ��highֵ�������ܷ�Ӻʹ���m����ʵ������Ӧ����height�����ø���
    ll ans = 0;
    for (auto elem : a) {
        ll overheight = elem - high;
        if (overheight > 0) {
            ans += overheight;
        }
    }
    if (ans >= m) return true;
    else return false; 
}
int main() {
    cin>>n>>m;
    vector<ll> a(n);
    for (auto &elem : a) cin>>elem;
    sort(a.begin(), a.end());

    ll highest_tree = *(a.end() - 1);
    ll l = 0, r = highest_tree;
    while (l != r) {//Ŀ�ģ����������Ԫ�أ������һ��true������֪��Ȼ��������һ���������У�������Ӧ��ǰ��ȫ��true������ȫ��false
        ll m = l + (r - l + 1) / 2;//���+1�����Բ�д������һ�£������д����ȥ��TLE�����ֹ�����ѭ����
        if (check(a, m) == true) {
            l = m;
        }
        else r = m - 1;
    }
    cout<<l<<endl;
    system("pause");
}