#include <bits/stdc++.h>
#define int long long
using namespace std;

int tree[200005];
int a[200005],b[200005];
int N;

int read(int indx){
    int sum=0;
    while(indx>0){
        sum=sum+tree[indx];
        indx-=(indx&(-indx));
    }
    return sum;
}
void update(int indx,int val){
    while(indx<=N){
        tree[indx]+=val;
        indx+=(indx&(-indx));
    }
}
int bin_search(int l,int r,int x)
{
    int m;
    while(l<r){
        m=(l+r)/2;
        if(read(m)>=x){
            r=m;
        }
        else
            l=m+1;
    }
    return r;
}

int32_t main()
{
    int  m;
   cin>>N>>m;
   if(N<=13){
    int tmp=1;
    for(int i=1;i<=N;i++) tmp*=i;
    if(m>tmp) {
        cout<<-1;
        return 0;
    }
   }
      
    a[N-1]=m-1;
    for (int i = N-1; i >0; --i)
    {
        a[i-1]+=a[i]/(N-i);
        a[i]%=(N-i);
    }
    a[0]%=N;

    memset(tree,0,sizeof(tree));
    for (int i = 0; i <N; ++i)
    {
        update(i+1,1);
    }
    for (int i = 0; i <N; ++i)
    {
        a[i]=bin_search(1,N,a[i]+1)-1;
        update(a[i] + 1, -1);   
    }
    for (int i = 0; i <N; ++i)
    {
        cout<<a[i]+1<<' ';
    }
    return 0;
}
