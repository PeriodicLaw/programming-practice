#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=10010,INF=1<<29;
int f[MAXN][MAXN][2],a[MAXN],b[MAXN];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i],&b[i]);
			f[i][i][0]=f[i][i][1]=0;
		}
		for(int i=n-1;i>=0;i--)
			for(int j=i+1;j<n;j++){
				f[i][j][0]=min(f[i+1][j][0]+a[i+1]-a[i],f[i+1][j][1]+a[j]-a[i]);
				if(f[i][j][0]>=b[i]) f[i][j][0]=INF;
				f[i][j][1]=min(f[i][j-1][0]+a[j]-a[i],f[i][j-1][1]+a[j]-a[j-1]);
				if(f[i][j][1]>=b[j]) f[i][j][1]=INF;
			}
		int ans=min(f[0][n-1][0],f[0][n-1][1]);
		if(ans>=INF) printf("No solution\n");
		else printf("%d\n",ans);
	}
	return 0;
}
