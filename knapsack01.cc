/*
 * 在数组中，找出一个组合，使得该组合的值为大于X的最小值，输出该值。
 * */

/*
 * 可以使用递归，遍历每一种情况，然后过滤，但是超时了。
 * 下面使用0/1背包的思想。背包大小为ntotal-X(其中ntotal为数组中所有
 * 数的和，而X为目标值)，则0/1背包的最大价值<=ntotal-X,则X<=ntotal-最大价值，
 * 则为大于X的最小和。
 * */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int m, n;
	while (cin >> m >> n) {
		vector<int> vec(m, 0);
		int ntotal = 0;
		for (int i = 0; i < m; i++) {
			cin >> vec[i];
			ntotal += vec[i];
		}

		int total = ntotal - n;//背包大小
		//求解0/1背包问题
		vector<vector<int>> mem(m, vector<int>(total + 1, -1));

		for (int j = 0; j <= total; j++) {
			mem[0][j] = (j >= vec[0] ? vec[0] : 0);
		}

		for (int i = 1; i < m; i++) {
			for (int j = 0; j <= total; j++) {
				mem[i][j] = mem[i - 1][j];
				if (j >= vec[i])
					mem[i][j] = max(mem[i][j], vec[i] + mem[i - 1][j - vec[i]]);
			}
		}
		cout << ntotal - mem[m-1][total] << endl;
	}
	return 0;
}
