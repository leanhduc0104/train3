#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000001;

long n;
long long x[MAXN], xopt [MAXN], a[MAXN], d[MAXN];
long long w[MAXN], c[MAXN], b, bk, fk, fopt;

void solution(){
    for ( int i = 1; i<=n ; i++ )
    cout << xopt[i] <<"\t";
    cout<<endl;
    cout<<fopt<<endl;
}

void TRY (int k){
    int tk = 0;
    if(bk >= w[k]) tk = 1;
    for ( int y = 0; y <= tk; y++){
        x[k] = y;
        bk -= w[k]*x[k];
        fk += c[k]*x[k];
    if (k == n){
        if ( fk > fopt ){
            /*for ( int i = 1; i <= n ; i++)
                xopt[i] = x[i];*/
            fopt = fk;
        }
    }else
        if ( fk + c[k+1]* ceil((1.0*bk)/ (1.0*w[k+1])) > fopt) TRY(k+1);
    bk += w[k]*x[k];
    fk -= c[k]*x[k];
    }
}

int main (){
    cin>>n>>b;
    for( int i = 1; i<=n; i++) {
        cin>>a[i];
        cin>>d[i];
    }
    vector< pair<double, int> > vect;
    for (int i = 1; i <= n; i++)
        vect.push_back(make_pair( (1.0*d[i]) / (1.0*a[i]), i) );
    sort(vect.begin(), vect.end(), greater<pair<double,int>>());

    for (int i = 0; i < n; i++) {
        w[i+1] = a[vect[i].second];
        c[i+1] = d[vect[i].second];
    }

    bk = b; fk = 0; fopt = 0;
    TRY(1);
    cout<<fopt;
    return 0;
}
