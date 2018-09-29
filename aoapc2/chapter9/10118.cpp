#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MAXN=41,INF=1<<29;
int f[MAXN][MAXN][MAXN][MAXN],g[MAXN][MAXN][MAXN][MAXN],a[MAXN],b[MAXN],c[MAXN],d[MAXN];
void update(int &ff,int &gg,int f,int g,int x){
	if(f+(bool)(g&x)>ff){
		ff=f+(bool)(g&x);
		gg=g^x;
	}
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int n;
	while(scanf("%d",&n)==1&&n){
		for(int i=1;i<=n;i++)
			scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				for(int k=0;k<=n;k++)
					for(int l=0;l<=n;l++)
						f[i][j][k][l]=-INF,g[i][j][k][l]=-1;
		f[0][0][0][0]=g[0][0][0][0]=0;
		int ans=0; 
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				for(int k=0;k<=n;k++)
					for(int l=0;l<=n;l++)
						if(__builtin_popcount(g[i][j][k][l])<5){
							if(i<n) update(f[i+1][j][k][l],g[i+1][j][k][l],f[i][j][k][l],g[i][j][k][l],1<<a[i+1]);
							if(j<n) update(f[i][j+1][k][l],g[i][j+1][k][l],f[i][j][k][l],g[i][j][k][l],1<<b[j+1]);
							if(k<n) update(f[i][j][k+1][l],g[i][j][k+1][l],f[i][j][k][l],g[i][j][k][l],1<<c[k+1]);
							if(l<n) update(f[i][j][k][l+1],g[i][j][k][l+1],f[i][j][k][l],g[i][j][k][l],1<<d[l+1]);
							if(f[i][j][k][l]>ans) ans=f[i][j][k][l];
						}
		printf("%d\n",ans);
	}
	return 0;
}
