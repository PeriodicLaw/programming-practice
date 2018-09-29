#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MAXN=120;
const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int f[MAXN][MAXN][2],a[MAXN][MAXN];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		char s[200];
		int n,m;
		scanf(" %s%d%d",s,&n,&m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&a[i][j]);
		memset(f,0,sizeof(f));
		for(int k=100;k>=0;k--){
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++){
					f[i][j][k%2]=f[i][j][(k+1)%2];
					if(a[i][j]==k){
						for(int t=0;t<4;t++){
							int x=i+dx[t],y=j+dy[t];
							if(x>=0&&x<n&&y>=0&&y<m&&f[x][y][(k+1)%2]+1>f[i][j][k%2])
								f[i][j][k%2]=f[x][y][(k+1)%2]+1;
						}
					}
				}
		}
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(f[i][j][0]>ans)
					ans=f[i][j][0];
		printf("%s: %d\n",s,ans);
	}
	return 0;
}
