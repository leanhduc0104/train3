#include<bits/stdc++.h>
#define Max 100
#define HNT ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

bool a[Max][Max];
bool t[Max][Max];
int N, M;
int x[Max];
int sz[Max];
int ans = INT_MAX;
int c[Max];

void input() {
    HNT
    cin >> N >> M;

    for(int i = 1; i <= M; i++)
        for(int j = 1; j <= M; j++) {
            a[i][j] = true;
        }
    for(int i = 1; i <= N; i++) {
       cin >> sz[i];
       for(int j = 0; j < sz[i]; j++){
            int k;
            cin >> k;
            t[i][k] = true;
       }
    }
    int K;
    cin >> K;
    for(int k = 0; k < K; k++){
        int i,j;
        cin >> i >> j;
        a[i][j] = false;
        a[j][i] = false;
    }

}
void solution() {
    int cnt = 0;
    int f = 0;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
            if(x[j] == i) cnt++;
        f = max(f, cnt);
        cnt = 0;
    }
    ans = min(f, ans);
}
bool check(int v, int k){
    for(int i = 1; i <= k-1; i++){
        if(a[i][k] == false && x[i] == v ) return false;
    }
    return true;
}
void Try(int k){

    for(int v = 1; v <= N; v++){
        if(t[v][k])
            if(check(v,k)){
                x[k] = v;
                c[v]++;
                if(k == M) solution();
                else {
                    int fmax = 0;
                    for(int i = 1; i <= N; i++) fmax = max(fmax, c[i]);
                    if(fmax < ans) Try(k + 1);
                }
                c[v]--;
            }
    }
}

int main(){
    input();
    Try(1);
    cout << ans << "\n";
}