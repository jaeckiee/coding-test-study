#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<int, vector<int>> pq;
	int n;
	int num;
	int result;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 0) {
			if (!pq.empty()) {
				result = pq.top();
				printf("%d\n", result);
				pq.pop();
			}
			else {
				printf("%d\n", 0);
			}
		}
		else {
			pq.push(num);
		}
	}
	return 0;
}