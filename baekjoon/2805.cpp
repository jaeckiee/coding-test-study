#include <iostream>
#include <vector>

using namespace std;

void merge(long long* arr, int left, int mid, int right) {
	int l, m;
	int index;
	long long* sorted;
	l = left;
	m = mid + 1;
	index = 0;
	sorted = new long long[right - left + 1];
	while (l <= mid && m <= right) {
		if (arr[l] < arr[m]) {
			sorted[index++] = arr[l++];
		}
		else {
			sorted[index++] = arr[m++];
		}
	}
	while (l <= mid) {
		sorted[index++] = arr[l++];
	}
	while (m <= right) {
		sorted[index++] = arr[m++];
	}
	for (int i = 0; i < (right - left + 1); i++) {
		arr[left + i] = sorted[i];
	}
}

void mergesort(long long* arr, int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		mergesort(arr, left, mid);
		mergesort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    int tmp;
    long long count;
    long long topnumber;
    long long nexttopnumber;
    long long* numarr;
    vector<long long> pq;
    vector<long long> countvec;
    long long tmpsumtree;
    long long sumtree;
    long long result;

    sumtree = 0;
    cin >> n >> m;
    numarr = new long long[n];
    for (int i = 0; i < n; i++){
        cin >> tmp;
        numarr[i] = tmp;
    }

    mergesort(numarr, 0, n - 1);

    tmp = -1;
    count = 0;
    for (int i = 0; i < n; i++){
        if (tmp != numarr[i]){
            if (i != 0){
                pq.push_back(tmp);
                countvec.push_back(count);
            }
            tmp = numarr[i];
            count = 1;
        }
        else{
            count++;
        }
        if (i == n - 1){
            pq.push_back(tmp);
            countvec.push_back(count);
        }
    }

    count = 0;
    while(1){
        topnumber = pq.back();
        count += countvec.back();
        pq.pop_back();
        countvec.pop_back();
        if (!pq.empty()){
            nexttopnumber = pq.back();
        }
        else{
            nexttopnumber = 0;
        }
        tmpsumtree = sumtree + count * (topnumber - nexttopnumber);
        if (tmpsumtree == m){
            result = nexttopnumber;
            break;
        }
        else if (tmpsumtree < m){
            sumtree = sumtree + count * (topnumber - nexttopnumber);
        }
        else{
            m = m - sumtree;
            if (m % count == 0){
                nexttopnumber = topnumber - (m / count);
            }
            else{
                nexttopnumber = topnumber - (m / count + 1);
            }
            result = nexttopnumber;
            break;
        }
    }

    cout << result;

    return 0;
}