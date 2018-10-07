#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MAXN=30;
bool a[MAXN][MAXN];
int c[MAXN][MAXN],f[MAXN][MAXN][MAXN][MAXN];
inline void update(int &f,int g){
	if(f==-1||g<f)
		f=g;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int n,m,k,count=0;
	while(scanf("%d%d%d",&n,&m,&k)==3){
		memset(a,0,sizeof(a));
		for(int i=0;i<k;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[x][y]=true;
		}
		c[0][0]=0;
		for(int i=1;i<=n;i++) c[i][0]=c[i-1][0]+a[i][0];
		for(int i=1;i<=m;i++) c[0][i]=c[0][i-1]+a[0][i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				c[i][j]=c[i-1][j]+c[i][j-1]-c[i-1][j-1]+a[i][j];
		for(int i=n;i;i--)
			for(int j=m;j;j--)
				for(int k=i;k<=n;k++)
					for(int l=j;l<=m;l++){
						int cnt=c[k][l]-c[i-1][l]-c[k][j-1]+c[i-1][j-1];
						if(cnt==0)
							f[i][j][k][l]=-1;
						else if(cnt==1)
							f[i][j][k][l]=0;
						else{
							f[i][j][k][l]=-1;
							for(int a=i;a<k;a++)
								if(f[i][j][a][l]>=0&&f[a+1][j][k][l]>=0)
									update(f[i][j][k][l],f[i][j][a][l]+f[a+1][j][k][l]+l-j+1);
							for(int b=j;b<l;b++)
								if(f[i][j][k][b]>=0&&f[i][b+1][k][l]>=0)
									update(f[i][j][k][l],f[i][j][k][b]+f[i][b+1][k][l]+k-i+1);
						}
					}
			printf("Case %d: %d\n",++count,f[1][1][n][m]);
	}
	return 0;
}

