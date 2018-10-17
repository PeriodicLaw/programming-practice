#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=120;
struct point{
	int x,y;
	point(int x=0,int y=0):x(x),y(y){}
	inline point operator-(const point &a)const{
		return point(x-a.x,y-a.y);
	}
}p0,p[MAXN],a[MAXN];
inline int cross(const point &a,const point &b){
	return a.x*b.y-a.y*b.x;
}
inline bool operator<(const point &a,const point &b){
	return cross(a-p0,b-p0)>0;
}
int n,m,f[MAXN][MAXN];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d%d",&a[i].x,&a[i].y);
		int ans=0;
		for(int i=0;i<n;i++){
			m=0;
			p0=a[i];
			for(int j=0;j<n;j++)
				if(a[j].y>p0.y||(a[j].y==p0.y&&a[j].x>p0.x))
					p[m++]=a[j];
			sort(p,p+m);
			memset(f,0xF0,sizeof(f));
			for(int i=0;i<m;i++)
				for(int j=i+1;j<m;j++){
					if(cross(p[i]-p0,p[j]-p0)==0) continue;
					bool oni=false,onj=false,in=false;
					for(int k=0;k<m;k++)
						if(cross(p[k]-p0,p[i]-p0)<=0&&cross(p[k]-p0,p[j]-p0)>=0&&cross(p[k]-p[i],p[j]-p[i])<0)
							if(cross(p[k]-p0,p[j]-p0)==0)
								onj=true;
							else if(cross(p[k]-p0,p[i]-p0)==0)
								oni=true;
							else
								in=true;
					if(!in)
						if(cross(p[i]-p0,p[j]-p[i])>=0){
							if(cross(p[i]-p0,p[j]-p0)>ans)
								ans=cross(p[i]-p0,p[j]-p0);
							if(!onj)
								f[i][j]=cross(p[i]-p0,p[j]-p0);
						}
					int ff=f[i][j];
					for(int k=0;k<i;k++)
						if(cross(p[i]-p[k],p[j]-p[i])>=0)
							if(f[k][i]+cross(p[i]-p0,p[j]-p0)>ff)
								ff=f[k][i]+cross(p[i]-p0,p[j]-p0);
					if(!oni&&!in)
						if(ff>ans)
							ans=ff;
					if(!oni&&!onj&&!in) f[i][j]=ff;
				}
		}
		printf("%.1lf\n",(double)ans/2);
	}
	return 0;
}
