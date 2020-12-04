#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

map<string, set<string>> tree;
set<string> visited;

int res = 1e9;

void dfs(string s, int n){

    if(s=="YOU") cout << n-2;

    visited.insert(s);

    for(auto it : tree[s]){
        if(visited.count(it) == 0) dfs(it, n+1);
    }
}

int main(){

    #ifdef DEBUG
        freopen("..\\input.txt", "r", stdin);
        clock_t tStart = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 1443;

    for(int i=0; i<N; i++){
        string s;
        cin >> s;

        int par = 0;
        while(s[par] != ')') par++;

        tree[s.substr(0, par)].insert(s.substr(par+1));
        tree[s.substr(par+1)].insert(s.substr(0, par));
    }

    dfs("SAN", 0);

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}