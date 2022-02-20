#include <iostream>
#include <string>

using namespace std;

void diffcheckareabool(bool** checkarea, string* area, int n, int x, int y) {
	if (checkarea[x][y] == false) {
		checkarea[x][y] = true;
		if (x > 0) {
			if (area[x][y] == area[x - 1][y]) {
				diffcheckareabool(checkarea, area, n, x - 1, y);
			}
		}
		if (y > 0) {
			if (area[x][y] == area[x][y - 1]) {
				diffcheckareabool(checkarea, area, n, x, y - 1);
			}
		}
		if (x < n - 1) {
			if (area[x][y] == area[x + 1][y]) {
				diffcheckareabool(checkarea, area, n, x + 1, y);
			}
		}
		if (y < n - 1) {
			if (area[x][y] == area[x][y + 1]) {
				diffcheckareabool(checkarea, area, n, x, y + 1);
			}
		}
	}
}

void nodiffcheckareabool(bool** checkarea, string* area, int n, int x, int y) {
	if (checkarea[x][y] == false) {
		checkarea[x][y] = true;
		if (x > 0) {
			if (area[x][y] == 'B'){
				if (area[x - 1][y] == 'B') {
					nodiffcheckareabool(checkarea, area, n, x - 1, y);
				}
			}
			else{
				if (area[x - 1][y] != 'B') {
					nodiffcheckareabool(checkarea, area, n, x - 1, y);
				}
			}
		}
		if (y > 0) {
			if (area[x][y] == 'B') {
				if (area[x][y - 1] == 'B') {
					nodiffcheckareabool(checkarea, area, n, x, y - 1);
				}
			}
			else {
				if (area[x][y - 1] != 'B') {
					nodiffcheckareabool(checkarea, area, n, x, y - 1);
				}
			}
		}
		if (x < n - 1) {
			if (area[x][y] == 'B') {
				if (area[x + 1][y] == 'B') {
					nodiffcheckareabool(checkarea, area, n, x + 1, y);
				}
			}
			else {
				if (area[x + 1][y] != 'B') {
					nodiffcheckareabool(checkarea, area, n, x + 1, y);
				}
			}
		}
		if (y < n - 1) {
			if (area[x][y] == 'B') {
				if (area[x][y + 1] == 'B') {
					nodiffcheckareabool(checkarea, area, n, x, y + 1);
				}
			}
			else {
				if (area[x][y + 1] != 'B') {
					nodiffcheckareabool(checkarea, area, n, x, y + 1);
				}
			}
		}
	}
}

int diffredgreen(int n, string* area) {
	int result;
	bool** checkarea;
	
	result = 0;
	checkarea = new bool*[n];
	for (int i = 0; i < n; i++) {
		checkarea[i] = new bool[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			checkarea[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (checkarea[i][j] == false) {
				diffcheckareabool(checkarea, area, n, i, j);
				result++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		delete[] checkarea[i];
	}
	delete[] checkarea;
	return result;
}

int nodiffredgreen(int n, string* area) {
	int result;
	bool** checkarea;

	result = 0;
	checkarea = new bool*[n];
	for (int i = 0; i < n; i++) {
		checkarea[i] = new bool[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			checkarea[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (checkarea[i][j] == false) {
				nodiffcheckareabool(checkarea, area, n, i, j);
				result++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		delete[] checkarea[i];
	}
	delete[] checkarea;
	return result;
}

void solveareaproblem() {
	int n;
	int numdiffredgreen;
	int numnodiffredgreen;
	string* area;

	cin >> n;
	area = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> area[i];
	}

	numdiffredgreen = diffredgreen(n, area);
	numnodiffredgreen = nodiffredgreen(n, area);


	printf("%d %d", numdiffredgreen, numnodiffredgreen);
	delete[] area;
}

int main() {
	solveareaproblem();
	return 0;
}