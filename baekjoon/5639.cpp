#include <iostream>
#include <vector>

using namespace std;

void change(int* numarr, int first, int last){
    int tmp;
    int firstnum;
    int pivot;
    if (first < last){
        if (last == first + 1){
            tmp = numarr[first];
            numarr[first] = numarr[last];
            numarr[last] = tmp;
        }
        else{
            firstnum = numarr[first];
            pivot = first;
            for (int i = first + 1; i <= last; i++){
                if (numarr[i] < firstnum){
                    pivot = pivot + 1;
                }
            }
            for (int i = first; i < last; i++){
                numarr[i] = numarr[i + 1];
            }
            numarr[last] = firstnum;
            if (pivot > first){
                change(numarr, first, pivot - 1);
            }
            change(numarr, pivot, last - 1);
        }
    }
}

int main(){
    int tmp;
    int* numarr;
    vector<int> v;

    while(cin >> tmp){
        v.push_back(tmp);
    }
    
    if (!v.empty()){
        numarr = new int[v.size()];
        for (int i = 0; i < v.size(); i++){
            numarr[i] = v[i];
        }
        change(numarr, 0, v.size() - 1);
        for (int i = 0; i < v.size(); i++){
            cout << numarr[i] << endl;
        }
    }

    return 0;
}