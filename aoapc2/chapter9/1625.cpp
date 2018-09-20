#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MAXN=5010,INF=1<<29;
char s1[MAXN],s2[MAXN];
int f[MAXN][MAXN],g[MAXN][MAXN];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		scanf(" %s",s1);
		scanf(" %s",s2);
		int n=strlen(s1),m=strlen(s2);
		for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) g[i][j]=0;
		for(int z=0;z<26;z++){
			int p1=n+1,q1=0;
			for(int i=1;i<=n;i++) if(s1[i-1]=='A'+z){p1=i;break;}
			for(int i=n;i;i--) if(s1[i-1]=='A'+z){q1=i;break;}
			int p2=m+1,q2=0;
			for(int i=1;i<=m;i++) if(s2[i-1]=='A'+z){p2=i;break;}
			for(int i=m;i;i--) if(s2[i-1]=='A'+z){q2=i;break;}
			for(int i=0;i<=n;i++)
				for(int j=0;j<=m;j++)
					if(i>=p1||j>=p2)
						if(i<q1||j<q2)
							g[i][j]++;
		}
		f[0][0]=0;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++){
				if(i||j) f[i][j]=INF;
				if(i&&f[i-1][j]+g[i-1][j]<f[i][j])
					f[i][j]=f[i-1][j]+g[i-1][j];
				if(j&&f[i][j-1]+g[i][j-1]<f[i][j])
					f[i][j]=f[i][j-1]+g[i][j-1];
			}
		printf("%d\n",f[n][m]);
	}
	return 0;
}