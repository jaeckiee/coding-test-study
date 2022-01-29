#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    long long* result;
    int x, y, w;
    vector<int> start;
    vector<int> end;
    vector<int> weight;

    cin >> n >> m;
    result = new long long[n];
    for (int i = 0; i < n; i++){
        result[i] = 5000000;
    }
    result[0] = 0;
    for (int i = 0; i < m; i++){
        cin >> x >> y >> w;
        start.push_back(x - 1);
        end.push_back(y - 1);
        weight.push_back(w);
    }

    for(int i = 0; i < n; i++){
        for (int j = 0; j < start.size(); j++){
            x = start[j];
            y = end[j];
            w = weight[j];
            if (result[x] != 5000000){
                if (result[y] > result[x] + w){
                    result[y] = result[x] + w;
                }
            }
        }
    }
    for (int j = 0; j < start.size(); j++){
        x = start[j];
        y = end[j];
        w = weight[j];
        if (result[x] != 5000000){
            if (result[y] > result[x] + w){
                cout << -1;
                return 0;
            }
        }
    }
    for (int i = 1; i < n; i++){
        if (result[i] != 5000000){
            cout << result[i] << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}