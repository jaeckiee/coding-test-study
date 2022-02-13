#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void cal(queue<int> prevnumq, queue<char> prevcharq, queue<int> afternumq, queue<char> aftercharq, int* result){
    int prevfront;
    char prevfrontchar;
    int tmpresult;
    int tmpnum;
    char tmpchar;
    queue<int> prevnumq1;
    queue<char> prevcharq1;
    queue<int> afternumq1;
    queue<char> aftercharq1;
    queue<int> prevnumq2;
    queue<char> prevcharq2;
    queue<int> afternumq2;
    queue<char> aftercharq2;
    if (prevcharq.empty()){
        if (prevnumq.empty()){
            tmpresult = afternumq.front();
            afternumq.pop();
            while(!afternumq.empty()){
                tmpnum = afternumq.front();
                tmpchar = aftercharq.front();
                afternumq.pop();
                aftercharq.pop();
                if (tmpchar == '+'){
                    tmpresult = tmpresult + tmpnum;
                }
                else if(tmpchar == '-'){
                    tmpresult = tmpresult - tmpnum;
                }
                else if(tmpchar == '*'){
                    tmpresult = tmpresult * tmpnum;
                }
            }
            *result = max(*result, tmpresult);
        }
        else{
            prevfront = prevnumq.front();
            prevnumq.pop();
            afternumq.push(prevfront);
            cal(prevnumq, prevcharq, afternumq, aftercharq, result);
        }
    }
    else{       
        prevnumq1 = prevnumq;
        prevcharq1 = prevcharq;
        afternumq1 = afternumq;
        aftercharq1 = aftercharq;
        prevnumq2 = prevnumq;
        prevcharq2 = prevcharq;
        afternumq2 = afternumq;
        aftercharq2 = aftercharq;
        afternumq1.push(prevnumq1.front());
        prevnumq1.pop();
        aftercharq1.push(prevcharq1.front());
        prevcharq1.pop();
        cal(prevnumq1, prevcharq1, afternumq1, aftercharq1, result);
        if (prevnumq2.size() > 1){
            prevfront = prevnumq2.front();
            prevfrontchar = prevcharq2.front();
            prevnumq2.pop();
            prevcharq2.pop();
            if (prevfrontchar == '+'){
                afternumq2.push(prevfront + prevnumq2.front());
            }
            else if (prevfrontchar == '-'){
                afternumq2.push(prevfront - prevnumq2.front());
            }
            else if (prevfrontchar == '*'){
                afternumq2.push(prevfront * prevnumq2.front());
            }
            prevnumq2.pop();
            if (!prevcharq2.empty()){
                aftercharq2.push(prevcharq2.front());
                prevcharq2.pop();
            }
            cal(prevnumq2, prevcharq2, afternumq2, aftercharq2, result);
        }
    }
}

int main(){
    int n;
    int tmpnum;
    char tmpchar;
    queue<int> numq;
    queue<int> resultnumq;
    queue<char> charq;
    queue<char> resultcharq;
    int* result = new int;
    *result = -2147483648;

    cin >> n;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            cin >> tmpnum;
            numq.push(tmpnum);
        }
        else{
            cin >> tmpchar;
            charq.push(tmpchar);
        }
    }

    cal(numq, charq, resultnumq, resultcharq, result);

    cout << *result; 

    return 0;
}