#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int w;
    int** value;
    int** product;

    cin >> n >> w;
    product = new int*[n + 1];
    value = new int*[n + 1];
    for (int i = 0; i < n + 1; i++){
        value[i] = new int[w + 1];
    }
    for (int i = 0; i < n + 1; i++){
        product[i] = new int[2];
    }
    for (int i = 1; i < n + 1; i++){
        cin >> product[i][0] >> product[i][1];
    }
    for (int i = 0; i < n + 1; i++){
        value[i][0] = 0;
    }
    for (int i = 0; i < w + 1; i++){
        value[0][i] = 0;
    }
    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < w + 1; j++){
            if (j - product[i][0] >= 0){
                value[i][j] = max(value[i - 1][j], value[i - 1][j - product[i][0]] + product[i][1]);
            }
            else{
                value[i][j] = value[i - 1][j];
            }
        }
    }
    cout << value[n][w];
    return 0;
}