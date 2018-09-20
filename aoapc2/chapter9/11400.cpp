#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=1050;
const LL INF=1LL<<62-1;
struct data{
	int v,k,c,l;
	bool operator<(const data &x)const{return v<x.v;}
}a[MAXN];
LL f[MAXN];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int n;
	while(cin>>n&&n){
		for(int i=1;i<=n;i++)
			cin>>a[i].v>>a[i].k>>a[i].c>>a[i].l;
		sort(a+1,a+n+1);
		f[0]=0;
		for(int i=1;i<=n;i++){
			f[i]=INF;
			LL sum=a[i].c*a[i].l;
			for(int j=i-1;j>=0;j--){
				if(f[j]+sum<f[i]) f[i]=f[j]+sum;
				sum+=a[i].c*a[j].l;
			}
			f[i]+=a[i].k;
		}
		printf("%lld\n",f[n]);
	}
	return 0;
}