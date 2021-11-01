#include<bits/stdc++.h>
using namespace std;
const int N = 1001;
int n, cur = 0, mt[N][N];
int x[N], xopt[N], fk, fopt, cmin = 1000001;

bool check[N];

void init(){
    xopt[0] = x[0] = 0;
    fk = 0;
    fopt = INT_MAX;
}

void solution(){
    for(int i = 0; i <= 2*n ; i++) {
        cout << xopt[i] << " ";
    }
    cout << fopt << endl;
}

void TRY (int k) {
    for(int v = 1; v <= 2*n; v++){
        if((k == 2*n) && !mt[v][0]) continue;
        if(!mt[x[k-1]][v]) continue;

        if(!check[v]) {
            if (v <= n){
                if (cur < 1){
                    x[k] = v;
                    check[v] = true;
                    cur++;
                    fk += mt[x[k-1]][v];

                    if (fk + cmin * (2*n - k + 1) < fopt ) TRY(k+1);

                    check[v] = false;
                    cur--;
                    fk -= mt[x[k-1]][v];
                }
            }
            else {
                if (check[v - n]) {
                    x[k] = v;
                    check[v] = true;
                    cur--;
                    fk += mt[x[k-1]][v];

                    if (k == 2*n) {
                        if (fk + mt[x[k]][0] < fopt ){
                            fopt = fk + mt[x[k]][0];
                            for( int i = 1; i <= 2*n; i++)
                                xopt[i] = x[i];
                        }
                    }
                    if (fk + cmin * (2*n - k + 1) < fopt ) TRY(k+1);

                    check[v] = false;
                    cur++;
                    fk -= mt[x[k-1]][v];
                }
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        check[i] = false;
    }
    for (int i = 0; i <= 2*n; i++) {
        for ( int j = 0; j <= 2*n; j++) {
            cin >> mt[i][j];
            if (mt[i][j] != 0)
            cmin = (cmin > mt[i][j])? mt[i][j] : cmin;
        }
    }
    init();
    TRY(1);
    cout << fopt;
    return 0;
}

