#include<bits/stdc++.h>
#define MAX 50
#define HNT   ios_base::sync_with_stdio(false);   cin.tie(0);
using namespace std;

int n,K,Q;
int d[MAX] , x[MAX], y[MAX], load[MAX], visit[MAX];
int segments;
int nbRoutes , ans;

void solution(){
    ans++ ;
    /*for(int k = 1; k <= K; k++){
        int s = y[k];
        printf("route[%d]: 0", k);
        for(int v = s; v != 0; v = x[v]){
            printf("%d ",v);
        }
        printf("0\n");
    }
    printf("--------------------\n");*/
}

int check(int v, int k){
    if(v > 0 && visit[v]) return 0;
    if(load[k] + d[v] > Q) return 0;
    return 1;

}

void input(){
    cin >> n >> K >> Q;
    for(int i = 1; i <= n; i++)
        cin >> d[i];
    d[0] = 0;
}

void Try_X(int s, int k){
    for(int v = 0; v <= n; v++){
        if(check(v,k)){
            x[s] = v;
            visit[v] = 1;
            load[k] += d[v];
            segments++;
            if(v > 0) Try_X(v,k);
            else {
                if(k == K){
                    if(segments == n + nbRoutes) solution();
                }
                else Try_X(y[k + 1], k + 1);
            }
            segments--;
            load[k] -= d[v];
            visit[v] = 0;
        }
    }
}

int check1(int v, int k){
    if(v == 0) return 1;
    if(load[k] + d[v] > Q) return 0;
    return !visit[v];
}

void Try_Y(int k){
    for(int v = y[k - 1] + 1; v <= n; v++){
        if(check1(v,k)){
            y[k] = v;
            segments++;
            visit[v] = 1;
            load[k] += d[v];
            if(k < K) Try_Y(k + 1);
            else {
                nbRoutes = segments;
                Try_X(y[1],1);
            }
            load[k] -= d[v];
            visit[v] = 0;
            segments--;
        }
    }
}

void solve(){
    for(int v = 1; v <= n; v++) visit[v] = 0;
    y[0] = 0;
    ans = 0;
    Try_Y(1);
    cout << ans << "\n";
}

int main(){
    HNT;
    input();
    solve();
    return 0;
}
