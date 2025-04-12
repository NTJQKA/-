//P3613 【深基15.例2】寄包柜
//cout<<string::size_type()<<" "<<vector<int>::size_type()<<" "<<vector<double>::size_type()<<" "<<vector<bool>::size_type()<<endl;
//上面那些就是检测几个容器size()函数返回类型的表达方式，忘了的时候可以在智能ide中打出来，就会有提示。实际上经过这一次踩坑应该就不会忘了
//上面几个size返回类型都是unsigned long long，所以在不加转换地使用size()函数并与一个int或long long的size比较时：
//1.最好不要对一个容器的size()-1，因为这可能导致空容器的长度由0变成unsigned long long上界
//2.确保这个手工的int或long long的size不是负数。根据《C++ primer》page 143，这种时候编译器会自动转换这个负数使之变成unsigned，这样就会生成一个很大的正数。这并不是我们的目的
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, q, opt;//option
int i, j, k;
int main() {
    cin>>n>>q;
    vector<vector<int>> a(n+1);//柜子下标从1开始，下面成员函数size时候总是记得-1+1即可，这样兼容起来比较省脑子
    while (q--) {
        cin>>opt;
        if (opt == 1) {
            cin>>i>>j>>k;
            if (a[i].size() < j + 1) a[i].resize(j+1);//格子下标也从1开始
            a[i][j] = k;
        }
        else {
            cin>>i>>j;
            cout<<a[i][j]<<endl;
        }
    }
    //cout<<125*1024*1024/4<<endl;//32768000个int
    //cout<<sqrt(125*1024*1024/4)<<endl;//最大开5724*5724的矩阵存int。即使内存限制512M时也只能开到10000*10000 1e4级别
    system("pause");
}