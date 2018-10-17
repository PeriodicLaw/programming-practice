#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MAXN=40100,MAXM=10100,INF=100000;
int n,m,d,w[MAXN],sw[MAXN],f[MAXN][2];
int solve(int maxw){
	f[0][0]=0,f[0][1]=INF;
	for(int i=2;i<=n;i+=2){
		f[i][0]=f[i][1]=INF;
		for(int j=1;j<=i/2&&j<=d;j++)
			if(sw[i]-sw[i-j]<=maxw&&sw[i-j]-sw[i-2*j]<=maxw){
				if(f[i-2*j][0]+1<f[i][1]) f[i][1]=f[i-2*j][0]+1;
				if(f[i-2*j][1]+1<f[i][0]) f[i][0]=f[i-2*j][1]+1;
			}
	}
	return f[n][(m-1)%2];
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int z;scanf("%d",&z);
	while(z--){
		scanf("%d%d%d",&n,&m,&d);
		int l=0;
		sw[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&w[i]);
			if(w[i]>l) l=w[i];
			sw[i]=sw[i-1]+w[i];
		}
		if(n%2||n<2*(m-1)){
			printf("BAD\n");
			continue;
		}
		int r=sw[n];
		while(l<r)
			if(solve((l+r)/2)<=m-1)
				r=(l+r)/2;
			else
				l=(l+r)/2+1;
		printf("%d\n",l);
	}
	return 0;
}
