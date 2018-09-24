#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MAXN=100,INF=1<<29;
int a[MAXN],f[MAXN][MAXN],g[MAXN][MAXN]; 
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int l,n;
	while(scanf("%d",&l)==1&&l){
		scanf("%d",&n);
		a[0]=0,a[n+1]=l;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=0;i<=n;i++) f[i][i+1]=0,g[i][i+1]=i;
		for(int _=2;_<=n+1;_++)
			for(int i=0;i<=n+1-_;i++){
				int j=i+_;
				f[i][j]=INF;
				for(int k=g[i][j-1];k<=g[i+1][j];k++)
					if(f[i][k]+f[k][j]<f[i][j])
						f[i][j]=f[i][k]+f[k][j],
						g[i][j]=k;
				f[i][j]+=a[j]-a[i];
			}
		printf("The minimum cutting is %d.\n",f[0][n+1]);
	}
	return 0;
}
