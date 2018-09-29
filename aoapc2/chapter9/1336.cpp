#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=1020;
const double INF=1000003000;
double f[MAXN][MAXN][2];
int n,x,sumd[MAXN];
double v;
struct data{
	int x,c,d;
	bool operator<(const data &a)const{
		return x<a.x;
	}
}a[MAXN];
void update(double &a,double b){
	if(b<a+1e-8) a=b;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	while(scanf("%d%lf%d",&n,&v,&x)==3&&n&&v&&x){
		int sumc=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].c,&a[i].d);
			sumc+=a[i].c;
		}
		sort(a+1,a+n+1);
		sumd[0]=0;for(int i=1;i<=n;i++) sumd[i]=sumd[i-1]+a[i].d;
		for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) f[i][j][0]=f[i][j][1]=INF;
		for(int i=1;i<=n;i++)
			f[i][i][0]=f[i][i][1]=sumc+abs(a[i].x-x)/v*sumd[n];
		for(int _=0;_<n-1;_++)
			for(int i=1;i<=n-_;i++){
				int j=i+_;
				int sd=sumd[i-1]+sumd[n]-sumd[j];
				if(i>=2){
					update(f[i-1][j][0],f[i][j][0]+(a[i].x-a[i-1].x)/v*sd);
					update(f[i-1][j][0],f[i][j][1]+(a[j].x-a[i-1].x)/v*sd);
				}
				if(j<n){
					update(f[i][j+1][1],f[i][j][0]+(a[j+1].x-a[i].x)/v*sd);
					update(f[i][j+1][1],f[i][j][1]+(a[j+1].x-a[j].x)/v*sd);
				}
			}
		double ans=INF;
		update(ans,f[1][n][0]);
		update(ans,f[1][n][1]);
		printf("%d\n",(int)ans);
	}
	return 0;
}
