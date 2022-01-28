#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(){
    int m, n;
    int x, y;
    int zerocount = 0;
    int onecount = 0;
    int prvonecount = 0;
    int tmponecount;
    int result = 0;
    int** tomato;
    queue<pair<int, int>> q;

    cin >> m >> n;
    tomato = new int*[n];
    for (int i = 0; i < n; i++){
        tomato[i] = new int[m];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> tomato[i][j];
            if (tomato[i][j] == 0){
                zerocount++;
            }
            else if (tomato[i][j] == 1){
                onecount++;
                q.push(pair<int, int>(i, j));
            }
        }
    }
    
    while(zerocount != 0){
        tmponecount = onecount - prvonecount;
        prvonecount = onecount;
        if (tmponecount == 0){
            result = -1;
            break;
        }
        else{
            result++;
            for (int i = 0; i < tmponecount; i++){
                x = q.front().first;
                y = q.front().second;
                q.pop();
                if (x - 1 >= 0){
                    if (tomato[x - 1][y] == 0){
                        tomato[x - 1][y] = 1;
                        onecount++;
                        zerocount--;
                        q.push(pair<int, int>(x - 1, y));
                    }
                }
                if (y - 1 >= 0){
                    if (tomato[x][y - 1] == 0){
                        tomato[x][y - 1] = 1;
                        onecount++;
                        zerocount--;
                        q.push(pair<int, int>(x, y - 1));
                    }
                }
                if (x + 1 < n){
                    if (tomato[x + 1][y] == 0){
                        tomato[x + 1][y] = 1;
                        onecount++;
                        zerocount--;
                        q.push(pair<int, int>(x + 1, y));
                    }
                }
                if (y + 1 < m){
                    if (tomato[x][y + 1] == 0){
                        tomato[x][y + 1] = 1;
                        onecount++;
                        zerocount--;
                        q.push(pair<int, int>(x, y + 1));
                    }
                }
            }
        }
    }

    cout << result;

    return 0;
}