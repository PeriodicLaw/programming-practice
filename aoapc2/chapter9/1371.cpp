#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MAXN=5010,MAXM=70;
char s1[MAXN],s2[MAXM];
int n,m,g[MAXN][MAXM];
inline int min(int x,int y){return x<y?x:y;}
bool dp(int maxg){
	memset(g,0x70,sizeof(g));
	for(int i=0;i<=n;i++) g[i][0]=i;
	for(int i=0;i<=m;i++) g[0][i]=i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			if(s1[i-1]==s2[j-1])
				g[i][j]=g[i-1][j-1];
			else
				g[i][j]=min(g[i-1][j],min(g[i][j-1],g[i-1][j-1]))+1;
		if(g[i][m]<=maxg)
			g[i][0]=0;
	}
	return g[n][0]==0;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d ",&t);
	while(t--){
		gets(s2);
		gets(s1);
		n=strlen(s1),m=strlen(s2);
		int l=0,r=m;
		while(l<r){
			if(dp((l+r)/2))
				r=(l+r)/2;
			else
				l=(l+r)/2+1;
		}
		printf("%d\n",l);
	}
	return 0;
}
