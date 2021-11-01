#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
int mulmod(int a, int b,int n) {
    int r = 0;
    while (b > 0) {
        if (b % 2 != 0) r = (r + a) % n;
        a = a * 2 % n;
        b = b / 2;
    }
    return r%n;
}
int power(int x,int y, int p)
{
    int res = 1;      
    x = x % p;  
    while (y > 0)
    {
        if (y & 1)
            res = mulmod(res,x,p);
 
        y = y>>1; 
        x = mulmod(x,x,p);
    }
    return res%p;
}
void solve(){
	int n,k,m;
	cin>>n>>k>>m;
	int p1=1;
	for(int i=n-k+1;i<=n;i++) p1=mulmod(p1,i,m);
	int p2=1;
	for(int i=1;i<=k;i++){
		p2=mulmod(p2,i,m);		
	}
	p2=power(p2,m-2,m);
	cout<<mulmod(p1,p2,m)<<'\n';	
}

int32_t main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int tt;
	cin>>tt;
	while(tt--) solve();

}

