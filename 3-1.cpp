#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

int main(){

    #ifdef DEBUG
        freopen("..\\input.txt", "r", stdin);
        clock_t tStart = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<pair<int, int>> taken;

    string w1, w2;

    cin >> w1 >> w2;

    int lastComma = -1;
    int x = 0, y = 0;

    for(int i=0; i<w1.length()+1; i++){
        if(i == w1.length() || w1[i] == ','){
            char dir = w1[lastComma + 1];
            int dis = atoi(w1.substr(lastComma+2, i-lastComma-2).c_str());

            int xOff = 0, yOff = 0;
            if(dir == 'U'){
                xOff = 0;
                yOff = 1;
            }else if(dir == 'D'){
                xOff = 0;
                yOff = -1;
            }else if(dir == 'L'){
                xOff = -1;
                yOff = 0;
            }else if(dir == 'R'){
                xOff = 1;
                yOff = 0;
            }

            for(int j=0; j<dis; j++){
                x+=xOff;
                y+=yOff;

                taken.insert({x, y});
            }

            lastComma = i;
        }
    }

    x = 0;
    y = 0;

    int res = 2e9;
    lastComma = -1;

    for(int i=0; i<w2.length()+1; i++){
        if(i == w2.length() || w2[i] == ','){
            char dir = w2[lastComma + 1];
            int dis = atoi(w2.substr(lastComma+2, i-lastComma-2).c_str());

            int xOff = 0, yOff = 0;
            if(dir == 'U'){
                xOff = 0;
                yOff = 1;
            }else if(dir == 'D'){
                xOff = 0;
                yOff = -1;
            }else if(dir == 'L'){
                xOff = -1;
                yOff = 0;
            }else if(dir == 'R'){
                xOff = 1;
                yOff = 0;
            }

            for(int j=0; j<dis; j++){
                x+=xOff;
                y+=yOff;

                if(taken.count({x, y})){
                    res = min(res, abs(x)+abs(y));
                }
            }

            lastComma = i;
        }
    }

    cout << res;


    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}