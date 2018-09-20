#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long LL;
const int MAXN=2000;
const double EPS=1e-6,INF=1000000;
pair<int,int> a[MAXN];
double f[MAXN][MAXN];
inline double dist(pair<int,int> &x,pair<int,int> &y){
	return sqrt((x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second));
}
inline void update(double &x,double y){
	if(y<x+EPS) x=y;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++)
			cin>>a[i].first>>a[i].second;
		for(int i=0;i<n;i++)
			for(int j=0;j<i;j++)
				f[i][j]=INF;
		f[1][0]=dist(a[0],a[1]);
		for(int i=1;i<n-1;i++)
			for(int j=0;j<i;j++){
				update(f[i+1][j],f[i][j]+dist(a[i],a[i+1]));
				update(f[i+1][i],f[i][j]+dist(a[j],a[i+1]));
			}
		double ans=INF;
		for(int i=0;i<n-1;i++)
			if(f[n-1][i]+dist(a[i],a[n-1])<ans+EPS)
				ans=f[n-1][i]+dist(a[i],a[n-1]);
		printf("%.2lf\n",ans);
	}
	return 0;
}