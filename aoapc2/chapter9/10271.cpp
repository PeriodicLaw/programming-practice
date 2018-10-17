#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MAXN=5010,MAXK=1010;
LL f[MAXN][MAXN],g[MAXN][MAXN],a[MAXN];
inline LL sqr(LL x){return x*x;}
inline LL min(LL x,LL y){return x<y?x:y;}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		int k,n;scanf("%d%d",&k,&n);
		k+=8;
		memset(f,0x70,sizeof(f));
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		f[n-1][0]=0;
		for(int i=n-2;i>=0;i--)
			for(int j=0;j<=k;j++)
				if(i+3*j<=n)
					f[i][j]=min(f[i+1][j],f[i+2][j-1]+sqr(a[i]-a[i+1]));
		printf("%lld\n",f[0][k]);
	}
	return 0;
}

