#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> hole = make_pair(-1, -1);
bool** map;

void simulation(pair<int, int> red, pair<int, int> black, int cnt, int* count){
    int reddst;
    int blackdst;
    int redfirst;
    int blackfirst;
    int redsecond;
    int blacksecond;
    if (cnt > 10){
        return;
    }
    else{
        redfirst = red.first;
        blackfirst = black.first;
        redsecond = red.second;
        blacksecond = black.second;
        if ((map[redfirst + 1][redsecond] == true) || (map[blackfirst + 1][blacksecond] == true)){
            reddst = redfirst;
            blackdst = blackfirst;
            while(map[reddst + 1][redsecond] == true){
                reddst = reddst + 1;
            }
            while(map[blackdst + 1][blacksecond] == true){
                blackdst = blackdst + 1;
            }
            if ((blacksecond != hole.second) || (blackfirst > hole.first || hole.first > blackdst)){
                if ((redsecond == hole.second) && (redfirst <= hole.first && hole.first <= reddst)){
                    if (*count == -1){
                        *count = cnt;
                    }
                    else{
                        *count = min(*count, cnt);
                    }
                }
                else{
                    if (redsecond == blacksecond && reddst == blackdst){
                        if (redfirst > blackfirst){
                            red.first = reddst;
                            black.first = reddst - 1;
                        }
                        else{
                            black.first = blackdst;
                            red.first = blackdst - 1;
                        }
                        simulation(red, black, cnt + 1, count);
                    }
                    else{
                        red.first = reddst;
                        black.first = blackdst;
                        simulation(red, black, cnt + 1, count); 
                    }
                    red.first = redfirst;
                    black.first = blackfirst;
                }
            }
        }
        if ((map[redfirst - 1][redsecond] == true) || (map[blackfirst - 1][blacksecond] == true)){
            reddst = redfirst;
            blackdst = blackfirst;
            while(map[reddst - 1][redsecond] == true){
                reddst = reddst - 1;
            }
            while(map[blackdst - 1][blacksecond] == true){
                blackdst = blackdst - 1;
            }
            if ((blacksecond != hole.second) || (blackfirst < hole.first || hole.first < blackdst)){
                if ((redsecond == hole.second) && (redfirst >= hole.first && hole.first >= reddst)){
                    if (*count == -1){
                        *count = cnt;               
                    }
                    else{
                        *count = min(*count, cnt);
                    }
                }
                else{
                    if (redsecond == blacksecond && reddst == blackdst){
                        if (redfirst < blackfirst){
                            red.first = reddst;
                            black.first = reddst + 1;
                        }
                        else{
                            black.first = blackdst;
                            red.first = blackdst + 1;
                        }
                        simulation(red, black, cnt + 1, count);
                    }
                    else{
                        red.first = reddst;
                        black.first = blackdst;
                        simulation(red, black, cnt + 1, count); 
                    }
                    red.first = redfirst;
                    black.first = blackfirst;
                }                
            }
        }
        if ((map[redfirst][redsecond + 1] == true) || (map[blackfirst][blacksecond + 1] == true)){
            reddst = redsecond;
            blackdst = blacksecond;
            while(map[redfirst][reddst + 1] == true){
                reddst = reddst + 1;
            }
            while(map[blackfirst][blackdst + 1] == true){
                blackdst = blackdst + 1;
            }
            if ((blackfirst != hole.first) || (blacksecond > hole.second || hole.second > blackdst)){
                if ((redfirst == hole.first) && (redsecond <= hole.second && hole.second <= reddst)){
                    if (*count == -1){
                        *count = cnt;
                    }
                    else{
                        *count = min(*count, cnt);
                    }
                }
                else{
                    if (redfirst == blackfirst && reddst == blackdst){
                        if (redsecond > blacksecond){
                            red.second = reddst;
                            black.second = reddst - 1;
                        }
                        else{
                            black.second = blackdst;
                            red.second = blackdst - 1;
                        }
                        simulation(red, black, cnt + 1, count);
                    }
                    else{
                        red.second = reddst;
                        black.second = blackdst;
                        simulation(red, black, cnt + 1, count); 
                    }
                    red.second = redsecond;
                    black.second = blacksecond;
                }                   
            }
        }
        if ((map[redfirst][redsecond - 1] == true) || (map[blackfirst][blacksecond - 1] == true)){
            reddst = redsecond;
            blackdst = blacksecond;
            while(map[redfirst][reddst - 1] == true){
                reddst = reddst - 1;
            }
            while(map[blackfirst][blackdst - 1] == true){
                blackdst = blackdst - 1;
            }
            if ((blackfirst != hole.first) || (blacksecond < hole.second || hole.second < blackdst)){
                if ((redfirst == hole.first) && (redsecond >= hole.second && hole.second >= reddst)){
                    if (*count == -1){
                        *count = cnt;
                    }
                    else{
                        *count = min(*count, cnt);
                    }
                }
                else{
                    if (redfirst == blackfirst && reddst == blackdst){
                        if (redsecond < blacksecond){
                            red.second = reddst;
                            black.second = reddst + 1;
                        }
                        else{
                            black.second = blackdst;
                            red.second = blackdst + 1;
                        }
                        simulation(red, black, cnt + 1, count);
                    }
                    else{
                        red.second = reddst;
                        black.second = blackdst;
                        simulation(red, black, cnt + 1, count); 
                    }
                    red.second = redsecond;
                    black.second = blacksecond;
                }          
            }
        }
    }
}

int main(){
    int n, m;
    char tmp;
    int cnt = 1;
    int* count;
    pair<int, int> red = make_pair(-1, -1);
    pair<int, int> black = make_pair(-1, -1);
    count = new int;
    *count = -1;
    cin >> n >> m;
    map = new bool*[n];
    for (int i = 0; i < n; i++){
        map[i] = new bool[m];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> tmp;
            if (tmp == '#'){
                map[i][j] = false;
            }
            else{
                map[i][j] = true;
                if (tmp == 'R'){
                    red.first = i;
                    red.second = j;
                }
                else if (tmp == 'B'){
                    black.first = i;
                    black.second = j;
                }
                else if (tmp == 'O'){
                    hole.first = i;
                    hole.second = j;
                }
            }
        }
    }

    simulation(red, black, cnt, count);

    cout << *count;

    return 0;
}