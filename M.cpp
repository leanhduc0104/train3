#include <bits/stdc++.h>
using namespace std;

#define  HNT  ios_base::sync_with_stdio(false);  cin.tie(0);

int x[8];
int N, cnt = 0;

bool check (int v, int k) {
    for (int i = 1; i < k; i++) {
        if(x[i] == v) return false;
    }
    return true;
}

TRY (int k) {
    for (int v = 1; v < 10; v++){
        if (check(v,k)) {
            x[k] = v;
            if (k == 7){
                if(((100*x[1] + 10*x[2] + x[3]) - (100*x[7] + 62) +
                        (1000*x[4] + 100*x[5] + 10*x[6] + x[3])) == N)
                   {
                        cnt++;
                   }
            }
            else TRY (k + 1);
        }
    }
}

int main (){
    HNT;
    cin >> N;
    TRY (1);
    cout << cnt;
    return 0;
}
