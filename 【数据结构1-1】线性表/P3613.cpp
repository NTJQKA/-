//P3613 �����15.��2���İ���
//cout<<string::size_type()<<" "<<vector<int>::size_type()<<" "<<vector<double>::size_type()<<" "<<vector<bool>::size_type()<<endl;
//������Щ���Ǽ�⼸������size()�����������͵ı�﷽ʽ�����˵�ʱ�����������ide�д�������ͻ�����ʾ��ʵ���Ͼ�����һ�βȿ�Ӧ�þͲ�������
//���漸��size�������Ͷ���unsigned long long�������ڲ���ת����ʹ��size()��������һ��int��long long��size�Ƚ�ʱ��
//1.��ò�Ҫ��һ��������size()-1����Ϊ����ܵ��¿������ĳ�����0���unsigned long long�Ͻ�
//2.ȷ������ֹ���int��long long��size���Ǹ��������ݡ�C++ primer��page 143������ʱ����������Զ�ת���������ʹ֮���unsigned�������ͻ�����һ���ܴ���������Ⲣ�������ǵ�Ŀ��
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, q, opt;//option
int i, j, k;
int main() {
    cin>>n>>q;
    vector<vector<int>> a(n+1);//�����±��1��ʼ�������Ա����sizeʱ�����Ǽǵ�-1+1���ɣ��������������Ƚ�ʡ����
    while (q--) {
        cin>>opt;
        if (opt == 1) {
            cin>>i>>j>>k;
            if (a[i].size() < j + 1) a[i].resize(j+1);//�����±�Ҳ��1��ʼ
            a[i][j] = k;
        }
        else {
            cin>>i>>j;
            cout<<a[i][j]<<endl;
        }
    }
    //cout<<125*1024*1024/4<<endl;//32768000��int
    //cout<<sqrt(125*1024*1024/4)<<endl;//���5724*5724�ľ����int����ʹ�ڴ�����512MʱҲֻ�ܿ���10000*10000 1e4����
    system("pause");
}