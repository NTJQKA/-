#include <iostream>
#include <vector>
using namespace std;
int times[10000005];
//��������ʹ�ü������顣һ���ڴ�������int������ò�Ҫ��һǧ�����ϣ���1e7
//Ҳ����˵�����ÿһ��Ԫ�أ�����1e7�����������ط���̫��Ҫ��������;��󣬿��Կ������ü�������������ţ�1e7���Ͻ�ֹ��������
void counting_sort(vector<int> &a) {
    for (auto elem : a) times[elem]++;
    int ptr = 0;//����Ĭ��ÿ��Ԫ�ط�Χ��0��ĳһ���������ˣ�ʵ���ϴ���Ŀ��ע��Ԫ�ط�Χ���������ٿ�һ���
    for (auto &elem : a) {
        while (times[ptr] == 0) ptr++;
        elem = ptr;
        times[ptr]--;
    }
}
int main() {
    int n; cin>>n;
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;
    counting_sort(a);
    for (auto elem : a) cout<<elem<<" "; cout<<endl;
    system("pause");
}