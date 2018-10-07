#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MAXN=200,MAXM=50,INF=1000000;
int n,m,p[MAXM],f[MAXN];
int dp(int l){
	if(l==0) return 0;
	int mq[MAXN];
	f[0]=0;
	for(int j=1;j<=n;j++)
		f[j]=INF;
	for(int i=0;i<m;i++){
		int k=p[i]/l,qf=0,qb=0;
		for(int j=n;j>=n-k;j--){
			while(qb>qf&&f[mq[qb-1]]>f[j]) qb--;
			mq[qb++]=j;
		}
		for(int j=n;j>=0;j--){
			if(f[mq[qf]]+p[i]<f[j]) f[j]=f[mq[qf]]+p[i];
			if(mq[qf]==j) qf++;
			if(j>k){
				while(qb>qf&&f[mq[qb-1]]>f[j-k-1]) qb--;
				mq[qb++]=j-k-1;
			}
		}
	}
	return f[n];
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF&&n&&m){
		int l=0,r=0;
		for(int i=0;i<m;i++){
			scanf("%d",&p[i]);
			if(p[i]>r) r=p[i];
		}
		while(l+1<r){
			int ans=dp((l+r)/2);
			if(ans>=INF)
				r=(l+r)/2-1;
			else
				l=(l+r)/2;
		}
		if(dp(r)>=INF) printf("%d %d\n",l,dp(l));
		else printf("%d %d\n",r,dp(r));
	}
	return 0;
}
