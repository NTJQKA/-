//�������ϼ���ƽ��д�Ľⷨ�����ڿ��о����̫����
//����ƭ��˼·ֵ��ѧϰ�����ڲ���BFS����½���ģ�����⣬�����������ĸ������ߣ������䣬����ĸ��������������޲���֮��ײǽ��1���Ǿ���Ϊ���ڲ���
//�͹���80�ֵĵ㣬�ɼ�ֻ��1������hack���������⣬�Ǵ���İ������ĳЩ0ҲȾ����2�����ǵ��к����ָо����ĸ���������ֱ�����춼����1�����Ǻ����ȷʵ��ͨ�����ֻ��bfs˼���ˣ���Ϊbfs ÿһ�� ���������ĸ�������
#include <iostream>
#include <vector>
using namespace std;
int n;
int bfs(vector<vector<int>> &v, int i, int j) {
	if(v[i][j] == 1/* || v[i][j] == 2 */) return -1;
	else {
		//if(i == 0 || j == 0 || i == n-1 || j == n-1) return 0;
		/*else return bfs(v, i-1, j) + bfs(v, i+1, j) + bfs(v, i, j-1) + bfs(v, i, j+1);*/
		int ret = 0;
			for(int k = 0; k < i; ++k) {
				if(v[k][j] == 1 || v[k][j] == 2) {
					ret++;
					break;
				}
			}
			for(int k = i + 1; k < n; ++k) {
				if(v[k][j] == 1 || v[k][j] == 2) {
					ret++;
					break;
				}
			}
			for(int k = 0; k < j; ++k) {
				if(v[i][k] == 1 || v[i][k] == 2) {
					ret++;
					break;
				}
			}
			for(int k = j + 1; k < n; ++k) {
				if(v[i][k] == 1 || v[i][k] == 2){
					ret++;
					break;
				}
			}
			return ret;
	}
}
void fill_color(vector<vector<int>> &v) {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(bfs(v, i, j) == 4) v[i][j] = 2;
		}
	}
}
int main(){
	cin>>n;
	vector<int> v(n);
	vector<vector<int>> vec(n, v);
	for(auto &row : vec) {
		for(auto &elem : row) cin>>elem;
	}
	fill_color(vec);
	for(auto row : vec) {
		for(auto elem : row) cout<<elem<<" ";
		cout<<endl;
	}
	return 0;
}