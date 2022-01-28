#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    int x, y, w;
    int** result;

    cin >> n >> m;
    result = new int*[n];  
    for (int i = 0; i < n; i++){
        result[i] = new int[n];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            result[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++){
        cin >> x >> y >> w;
        if (result[x - 1][y - 1] != 0){
            result[x - 1][y - 1] = min(result[x - 1][y - 1], w);
        }
        else{
            result[x - 1][y - 1] = w;
        }
    }

    for (int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i != j){
                    if (result[i][k] != 0 && result[k][j] != 0 && result[i][j] != 0){
                        result[i][j] = min(result[i][j], result[i][k] + result[k][j]);
                    }
                    else if (result[i][k] != 0 && result[k][j] != 0 && result[i][j] == 0){
                        result[i][j] = result[i][k] + result[k][j];
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}