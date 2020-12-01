#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

int main(){

    // #ifdef DEBUG
    //     freopen("..\\input.txt", "r", stdin);
    //     clock_t tStart = clock();
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    

    int N = 137;

    map<ll, ll> m;
    ll arr[137] = {1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,13,1,19,1,19,6,23,1,23,6,27,1,13,27,31,2,13,31,35,1,5,35,39,2,39,13,43,1,10,43,47,2,13,47,51,1,6,51,55,2,55,13,59,1,59,10,63,1,63,10,67,2,10,67,71,1,6,71,75,1,10,75,79,1,79,9,83,2,83,6,87,2,87,9,91,1,5,91,95,1,6,95,99,1,99,9,103,2,10,103,107,1,107,6,111,2,9,111,115,1,5,115,119,1,10,119,123,1,2,123,127,1,127,6,0,99,2,14,0,0};

    for(ll n=0; n<=99; n++){
        for(ll v=0; v<=99; v++){
            m.clear();

            for(ll i=0; i<N; i++){
                m[i] = arr[(int)i];
            }

            m[1] = n;
            m[2] = v;

            for(int i=0; i<N-4 && m[i] != 99; i+=4){
                if(m[i] == 1){
                    m[m[i+3]] = m[m[i+1]] + m[m[i+2]];
                }else if(m[i] == 2){
                    m[m[i+3]] = m[m[i+1]] * m[m[i+2]];
                }
            }

            if(m[0] == 19690720LL){
                cout << 100*n + v;
                break;
            }
            
        }
    }

    

    // #ifdef DEBUG
    //     printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    // #endif

    return 0;
}