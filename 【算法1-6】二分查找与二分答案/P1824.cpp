//P1824 ��������ţ
//����⿴�ƶ��ִ�˼�룬ʵ��ö�ٴ𰸵�˼�롣��������ֻ������ƽ��/���������Ƚ�С��ö�ٶ��ѣ����Ż��ֶ�
//��ʹ������int��ô��������Ҳ����ö�ٴ�/���������𰸵Ŀ��ܵ�
//�о�����ö�ٴ�˼�����⣬check��������ά��ָ����߼�Ҳ������д����һ�����˺þã�����ֵ���Ż�һ�£��Ժ��ٿ�����
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, c;
bool check(vector<int> &b, int ans) {
    int ptr = 1;
    int possibile_cow_num = 1;//b[0]�϶���0����˵�Ҳһ�����һֻ������ptr�Ͳ���0��ʼ��
    while (ptr != n) {
        int sum = 0;
        while (ptr != n && sum < ans) {
            sum += b[ptr];
            ptr++;
        }
        if (sum < ans) break;//���������while������������sum < ans��˵��ptr��n�ˣ��������Ҳû�ܷ������䳤��Ҫ��ֱ��break
        else possibile_cow_num++;
    }
    return possibile_cow_num >= c;
}
int main() {
    cin>>n>>c;
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;
    sort(a.begin(), a.end());

    vector<int> b(n);//������飬��Ϊ�����������������Ǳ����㣬���������
    for (int i = 1; i < n; ++i) b[i] = a[i] - a[i-1];

    int l = 1, r = a[n-1] - a[0];
    while (l != r) {
        int m = l + (r - l + 1) / 2;
        if (check(b, m) == true) l = m;
        else r = m - 1;
    }
    cout<<l<<endl;
    system("pause");
}