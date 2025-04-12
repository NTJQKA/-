//过年在老家用平板写的解法，现在看感觉码风太差了
//不过骗分思路值得学习，我在不会BFS情况下仅仅模拟题意，往上下左右四个方向走，不拐弯，如果四个方向在走了有限步数之后撞墙（1）那就认为是内部点
//就过了80分的点，可见只有1个点能hack到我这个歪解，是错误的把外面的某些0也染成了2，就是地中海那种感觉，四个方向往外直线延伸都能碰1，但是和外界确实连通。这个只能bfs思想了，因为bfs 每一步 都可以往四个方向走
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