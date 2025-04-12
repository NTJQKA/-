//P1157 组合的输出
//也算是一个典型了，这种答案数组达到定长之后作为dfs结尾的题甚至不需要往dfs函数里填cnt参数
//没剪枝，因为n还不够大，剪了没明显收益，反而判断的开销可能更大
//如果剪枝的话暂时有两种想法：
//1.可行性剪枝，比如ans.size()==1时，if ans[0] = n - r + 2, 直接return，因为肯定是在第一层，这样就退出所有操作了
//2.结果状态判断剪枝（自己起的名字），构造一个最终数组，这个很好做，比如样例对应的最后一组肯定是3, 4, 5，如果得到这个了，剪断之后所有操作。
//但是用递归函数好像有点难实现，用栈来模拟好像很不错，直接clear()
//这么模拟也有问题：
//1.问了deepseek之后发现逻辑还是差别很多，并不是顺序到3 4 5这种情况，反而是最早被压在栈底的
//2.然后剪枝的最终优化是：每一步都可能剪。就像奇怪的电梯那道题记录到每一层的最少步数，保证任何栈深度下都可以被剪枝，这才是完美剪枝
//  没有排除所有无效情况的都是“部分剪枝”
//3.stack不能clear。其他容器的clear都是O(n)的，需要自己做一个数据结构才能写出O(1)的clear，改指针而不是释放内存的方式
//  用一个bool flag放进while的判断里面也不是不行，但是每次判断会多一个O(1)的开销，心里堵得慌
#include <iostream>
#include <vector>
#include <iomanip>
#include <stack>
using namespace std;
int n, r;
vector<int> ans;
void dfs() {
    if (ans.size() == r) {
        for (auto elem : ans) cout << setw(3) << elem;
        cout<<endl;
        return;
    }
    else {
        for (int back = ans.empty()? 0 : ans.back(), i = back + 1; i <= n; ++i) {
            if (r - ans.size() - 1 > n - i) continue;//剪枝
            else {
                ans.push_back(i);
                dfs();
                ans.pop_back();//回溯
            }
        }
    }
    return;
}
int main() {
    cin>>n>>r;
    /*vector<int> l(n+1);
    for (int i = 1; i <= n; ++i) {
        l[i] = n - i;
    }*/
    //不做这个数组了，因为做了还得当参数传进函数里，已经O(1)了，还不如用n-i那个运算的O(1)
    dfs();
    system("pause");
}
//就递归写法而言也能优化，本题特性下不需要一个a[n]数组存使用状态，因为只要从比ans数组的最后一个数大1的数开始搜索就一定是true的
//进行去bool状态数组优化，最慢点70ms减到了9ms，再做搜索剪枝发现又由9ms减到了5ms，可见搜索的常数优化不一定在剪枝，也可能在状态数组优化