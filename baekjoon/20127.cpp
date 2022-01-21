#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int result;
    int* nums;
    int inccnt = 0;
    int deccnt = 0;
    int incidx;
    int decidx;
    int decresult;
    int incresult;

    cin >> n;
    nums = new int[n];
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    if (n < 3){
        result = 0;
    }
    else{
        result = -1;
        incresult = n + 1;
        decresult = n + 1;
        for (int i = 0; i < (n - 1); i++){
            if (nums[i] > nums[i + 1]){
                inccnt++;
                incidx = i + 1;
            }            
        }
        if (inccnt < 2){
            if (inccnt == 0){
                incresult = 0;
            }
            else{
                if (nums[0] >= nums[n -1]){
                    incresult = incidx;
                }
            }
        }

        for (int i = 0; i < (n - 1); i++){
            if (nums[i] < nums[i + 1]){
                deccnt++;
                decidx = i + 1;
            }            
        }
        if (deccnt < 2){
            if (deccnt == 0){
                decresult = 0;
            }
            else{
                if (nums[0] <= nums[n -1]){
                    decresult = decidx;
                }
            }
        }

        if ((incresult != n + 1) || (decresult != n + 1)){
            result = min(incresult, decresult);
        }
    }
    cout << result;

    return 0;
}