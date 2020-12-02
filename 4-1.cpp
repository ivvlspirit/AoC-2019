#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

bool hasDouble(int n){
    int last = n%10;
    n/=10;

    while(n>0){
        if(n%10 == last) return true;

        last = n%10;
        n/=10;
    }

    return false;
}

bool increases(int n){
    int last = n%10;
    n/=10;

    while(n>0){
        if(last < n%10) return false;

        last = n%10;
        n/=10;
    }

    return true;
}



int main(){

    // #ifdef DEBUG
    //     freopen("..\\input.txt", "r", stdin);
    //     clock_t tStart = clock();
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a = 138307;
    int b = 654504;

    int res = 0;

    for(int i=a; i<=b; i++){
        if(hasDouble(i) && increases(i)) res++;
    }

    cout << res;

    // #ifdef DEBUG
    //     printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    // #endif

    return 0;
}