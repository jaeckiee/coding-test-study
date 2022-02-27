#include <iostream>
#include <algorithm>
using namespace std;

int tetromino(int i, int j, int** map, int n, int m) {
	int maxnum;
	int tmpnum;
	maxnum = 0;
	if (m > j + 3) {
		tmpnum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
		maxnum = max(maxnum, tmpnum);
	}
	if (m > j + 2 && n > i + 1) {
		tmpnum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2];
		maxnum = max(maxnum, tmpnum);
		tmpnum = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
		maxnum = max(maxnum, tmpnum);
		tmpnum = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i][j + 2];
		maxnum = max(maxnum, tmpnum);
	}
	if (m > j + 1 && n > i + 2) {
		tmpnum = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
		maxnum = max(maxnum, tmpnum);
		tmpnum = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j];
		maxnum = max(maxnum, tmpnum);
	}
	if (m > j + 1 && n > i + 1) {
		tmpnum = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1];
		maxnum = max(maxnum, tmpnum);
	}
	if (m > j + 2 && n > i + 1) {
		tmpnum = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
		maxnum = max(maxnum, tmpnum);
		tmpnum = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i][j + 2];
		maxnum = max(maxnum, tmpnum);
	}
	if (m > j + 1 && n > i + 2) {
		tmpnum = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
		maxnum = max(maxnum, tmpnum);
		tmpnum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
		maxnum = max(maxnum, tmpnum);
		tmpnum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j + 1];
		maxnum = max(maxnum, tmpnum);
	}
	if (m > j && n > i + 3) {
		tmpnum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
		maxnum = max(maxnum, tmpnum);
	}
	if (j > 0 && n > i + 2) {
		tmpnum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j - 1];
		maxnum = max(maxnum, tmpnum);
	}
	if (j > 0 && n > i + 2) {
		tmpnum = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 2][j - 1];
		maxnum = max(maxnum, tmpnum);
		tmpnum = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 2][j];
		maxnum = max(maxnum, tmpnum);
	}
	if (j > 1 && n > i + 1) {
		tmpnum = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 1][j - 2];
		maxnum = max(maxnum, tmpnum);
	}
	if (j > 0 && m > j + 1 && n > i + 1) {
		tmpnum = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 1][j + 1];
		maxnum = max(maxnum, tmpnum);
		tmpnum = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i][j + 1];
		maxnum = max(maxnum, tmpnum);
	}
	return maxnum;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	int** map;
	int maxnum;
	cin >> n >> m;
	map = new int* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	maxnum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			maxnum = max(maxnum, tetromino(i, j, map, n, m));
		}
	}
	cout << maxnum;
	return 0;
}