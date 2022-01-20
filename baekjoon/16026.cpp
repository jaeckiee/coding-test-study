#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    int result = 0;
    int tmp;
    priority_queue<int, vector<int>, greater<int>> pq;
    int q = 0;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++){
        cin >> tmp;
        if (tmp == 10){
            result++;
        }
        else{
            if (tmp % 10 == 0){
                pq.push(tmp / 10);
            }
            else{
                q = q + tmp / 10;
            }
        }
    }

    while(m != 0){
        if(!pq.empty()){
            tmp  = pq.top();
            if (m + 1 < tmp){
                result = result + m;
                m = 0;
            }
            else{
                result = result + tmp;
                m = m - (tmp - 1);
            }
            pq.pop();
        }
        else{
            result = result + min(m, q);
            break;            
        }
    }
    
    cout << result;
    return 0;
}