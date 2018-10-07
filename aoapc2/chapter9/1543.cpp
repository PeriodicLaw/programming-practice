#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long LL;
const int MAXN=50;
const double INF=1000,PI=asin(1)*2;
double f[MAXN][MAXN],p[MAXN];
inline double s(int i,int j){
	return sin(2*PI*(p[j]-p[i]))/2;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int n,m;
	while(scanf("%d%d",&n,&m)==2&&n&&m){
		for(int i=0;i<n;i++)
			scanf("%lf",&p[i]);
		double ans=0;
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++) for(int k=1;k<=m;k++) f[j][k]=-INF;
			f[i][1]=0;
			for(int j=i+1;j<n;j++)
				for(int k=2;k<=m;k++){
					f[j][k]=-INF;
					for(int l=i;l<j;l++)
						if(f[l][k-1]+s(l,j)>f[j][k])
							f[j][k]=f[l][k-1]+s(l,j);
				}
			for(int j=i+1;j<n;j++)
				if(f[j][m]+s(j,i)>ans)
					ans=f[j][m]+s(j,i);
		}
		printf("%.6lf\n",ans);
	}
	return 0;
}
