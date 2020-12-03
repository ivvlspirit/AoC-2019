#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

int input;
int N = 678;

vector<int> arr;
map<int, int> len;

int getParam(int n, int mode){
    if(mode == 0) return arr[arr[n]];
    else if(mode == 1) return arr[n];
    else return -1;
}

int startProgram(){
    int opcode;
    int modes[10];
    int params[10];
    
    for(int i=0; i<N; i+=len[opcode]){

        int arri = arr[i];
        opcode = arri%100;

        arri/=100;

        for(int j=0; j<len[opcode]-1; j++) {
            modes[j] = arri%10;
            arri/=10;
        }


        if(opcode == 1){
            params[0] = getParam(i+1, modes[0]);
            params[1] = getParam(i+2, modes[1]);

            arr[arr[i+3]] = params[0] + params[1];
        } else if(opcode == 2){
            params[0] = getParam(i+1, modes[0]);
            params[1] = getParam(i+2, modes[1]);

            arr[arr[i+3]] = params[0] * params[1];
        } else if(opcode == 3){
            arr[arr[i+1]] = input;
        } else if(opcode == 4){
            params[0] = getParam(i+1, modes[0]);

            cout << "Output: " << params[0] << endl;
        } else if(opcode == 99){
            return 0;
        } else {
            return 404;
        }
    }

    return 501;

}


int main(){

    #ifdef DEBUG
        freopen("..\\input.txt", "r", stdin);
        clock_t tStart = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int lastComma = -1;

    string s;
    cin >> s;

    vector<int> code;

    len[1] = 4;
    len[2] = 4;
    len[3] = 2;
    len[4] = 2;
    len[99] = 1; 

    for(int i=0; i<s.length()+1; i++){
        if(i==s.length() || s[i] == ','){
            int comm = atoi(s.substr(lastComma+1, i-lastComma-1).c_str());
            code.push_back(comm);

            lastComma = i;
        }
    }

    for(int i=0; i<N; i++){
        arr.push_back(code[i]);
    }

    input = 1;

    cout << "The program returned: " << startProgram() << endl;

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}