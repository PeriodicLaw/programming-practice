#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<utility>
using namespace std;
typedef long long LL;
inline int min(int x,int y){return (x<y)?x:y;}
typedef pair<LL,LL> point;
#define x first
#define y second
#define mp make_pair
const int MAXN=100,MAXM=1200;
const LL INF=1e13;
inline LL cross(const point &a,const point &b){
	return a.x*b.y-a.y*b.x;
}
inline LL dot(const point &a,const point &b){
	return a.x*b.x+a.y*b.y;
}
inline point operator+(const point &a,const point &b){
	return mp(a.x+b.x,a.y+b.y);
}
inline point operator-(const point &a,const point &b){
	return mp(a.x-b.x,a.y-b.y);
}
point p[MAXN];
int n,l[MAXM],r[MAXM];
LL f[MAXN],c[MAXM];
bool light(const point &l,int a){
	return cross(l-p[a],p[(a+1)%n]-p[a])>0&&cross(l-p[(a+1)%n],p[(a+1)%n]-p[a])>0;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	while(scanf("%d",&n)&&n){
		for(int i=0;i<n;i++) scanf("%lld%lld",&p[i].x,&p[i].y);
		int m;scanf("%d",&m);
		for(int i=0;i<m;i++){
			point q;scanf("%lld%lld%lld",&q.x,&q.y,&c[i]);
			l[i]=0,r[i]=0;
			for(int j=0;j<2*n-1;){
				int k=j;
				while(k<2*n-1&&light(q,k%n)) k++;
				if(k>j&&k-j>r[i]-l[i])
					r[i]=k,l[i]=j;
				j=k+1;
			}
		}
		LL ans=INF;
		for(int i=0;i<n;i++){
			f[i]=0;
			for(int j=i+1;j<=i+n;j++) f[j]=INF;
			for(int j=i;j<i+n;j++)
				for(int k=0;k<m;k++)
					if(l[k]<=j&&f[j]+c[k]<f[min(i+n,r[k])])
						f[min(i+n,r[k])]=f[j]+c[k];
			if(f[i+n]<ans) ans=f[i+n];
		}
		if(ans>=INF)
			printf("Impossible.\n");
		else
			printf("%lld\n",ans);
	}
	return 0;
}
