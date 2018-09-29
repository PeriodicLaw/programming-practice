#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MAXN=150,MAXM=3020,c[10]={6,2,5,5,4,5,6,3,7,6};
int n,m,f[MAXN][MAXM],g[MAXN][MAXM];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int count=0;
	while(scanf("%d",&n)==1&&n){
		scanf("%d",&m);
		memset(f,0,sizeof(f));
		for(int i=0;i<=n;i++)
			for(int j=0;j<m;j++)
				f[i][j]=(j==0)?0:-1,
				g[i][j]=-1;
		for(int i=0;i<=n;i++)
			for(int j=0;j<m;j++)
				for(int k=9;k>=0;k--)
					if(i>=c[k]&&f[i-c[k]][(j*10+k)%m]>=0&&f[i-c[k]][(j*10+k)%m]+1>f[i][j]){
						f[i][j]=f[i-c[k]][(j*10+k)%m]+1;
						g[i][j]=k;
					}
		printf("Case %d: ",++count);
		if(g[n][0]==-1)
			printf("-1");
		else
			for(int i=n,j=0;g[i][j]>=0;){
				int t=g[i][j];
				printf("%d",t);
				i-=c[t],j=(j*10+t)%m;
			}
		printf("\n");
	}
	return 0;
}

