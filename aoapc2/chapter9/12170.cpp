#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=120,MAXM=MAXN*MAXN*2;
const LL INF=1e15;
int n,m,h[MAXN],mq[MAXM];
LL d,x[MAXM],f[2][MAXM];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		m=0;
		for(int i=0;i<n;i++){
			scanf("%d",&h[i]);
			for(int j=1-n;j<n;j++)
				if(h[i]+j*d>=0)
					x[m++]=h[i]+(LL)j*d;
		}
		sort(x,x+m);
		m=unique(x,x+m)-x;
		for(int i=0;i<m;i++) f[0][i]=INF;
		f[0][lower_bound(x,x+m,h[0])-x]=0;
		int cur=0;
		for(int i=1;i<n;i++){
			cur^=1;
			int qf=0,qb=0,b=0;
			for(int j=0;j<m;j++){
				while(qf<qb&&x[mq[qf]]<x[j]-d) qf++;
				while(b<m&&x[b]<=x[j]+d){
					while(qf<qb&&f[cur^1][b]<f[cur^1][mq[qb-1]]) qb--;
					mq[qb++]=b;
					b++;
				}
				f[cur][j]=abs(h[i]-x[j])+f[cur^1][mq[qf]];
				if(f[cur][j]>INF) f[cur][j]=INF;
			}
		}
		LL ans=f[cur][lower_bound(x,x+m,h[n-1])-x];
		if(ans>=INF)
			printf("impossible\n");
		else
			printf("%lld\n",ans);
	}
	return 0;
}
