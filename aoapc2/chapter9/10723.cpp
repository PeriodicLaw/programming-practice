#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MAXN=50,INF=1<<29;
char s1[MAXN],s2[MAXN];
LL f[MAXN][MAXN],g[MAXN][MAXN];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d ",&t);
	for(int tt=1;tt<=t;tt++){
		gets(s1);
		gets(s2);
		int n=strlen(s1),m=strlen(s2);
		for(int i=0;i<=n;i++) f[i][0]=i,g[i][0]=1;
		for(int j=0;j<=m;j++) f[0][j]=j,g[0][j]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(s1[i-1]==s2[j-1])
					f[i][j]=f[i-1][j-1]+1,
					g[i][j]=g[i-1][j-1];
				else if(f[i-1][j]<f[i][j-1])
					f[i][j]=f[i-1][j]+1,
					g[i][j]=g[i-1][j];
				else if(f[i-1][j]>f[i][j-1])
					f[i][j]=f[i][j-1]+1,
					g[i][j]=g[i][j-1];
				else
					f[i][j]=f[i-1][j]+1,
					g[i][j]=g[i-1][j]+g[i][j-1];
		printf("Case #%d: %lld %lld\n",tt,f[n][m],g[n][m]);
	}
	return 0;
}
