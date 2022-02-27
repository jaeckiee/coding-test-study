#include <iostream>
#include <string>

using namespace std;

int main() {
	string str1;
	string str2;
	int len1, len2;
	int** numarr;

	cin >> str1 >> str2;
	len1 = str1.length();
	len2 = str2.length();
	numarr = new int*[len1 + 1];
	for (int i = 0; i < (len1 + 1); i++) {
		numarr[i] = new int[len2 + 1];
	}
	for (int i = 0; i < (len2 + 1); i++) {
		numarr[0][i] = 0;
	}
	for (int i = 0; i < (len1 + 1); i++) {
		numarr[i][0] = 0;
	}
	for (int i = 1; i < (len1 + 1); i++) {
		for (int j = 1; j < (len2 + 1); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				numarr[i][j] = numarr[i - 1][j - 1] + 1;
			}
			else {
				if (numarr[i][j - 1] > numarr[i - 1][j]) {
					numarr[i][j] = numarr[i][j - 1];
				}
				else {
					numarr[i][j] = numarr[i - 1][j];
				}
			}
		}
	}
	cout << numarr[len1][len2];
	return 0;
}