#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<utility>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> point;
#define x first
#define y second
#define mp make_pair
const LL MAXN=100,INF=1LL<<60;
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
inline point operator*(const point &a,int b){
	return mp(a.x*b,a.y*b);
}
inline point operator/(const point &a,int b){
	return mp(a.x/b,a.y/b);
}
inline bool intersect(const point &a,const point &b,const point &c,const point &d){
//a-b c-d
	return cross(b-a,c-a)*cross(b-a,d-a)<0&&cross(d-c,a-c)*cross(d-c,b-c)<0;
}
inline bool online(const point &a,const point &b,const point &c){
//a b-c
	return cross(a-b,a-c)==0&&dot(a-b,a-c)<0;
}
bool flag;
inline int inpolygon(const point &a,point p[],int n){
//-1:out 0:on 1:in
	int wn=0;
	for(int i=0;i<n;i++){
		if(p[i]==a||online(a,p[i],p[(i+1)%n])) return 0;
		LL t=cross(p[(i+1)%n]-p[i],a-p[i]);
		if(t>0&&p[i].y<=a.y&&p[(i+1)%n].y>a.y) wn++; //HERE WA!!
		if(t<0&&p[i].y>a.y&&p[(i+1)%n].y<=a.y) wn--;
	}
	return wn?1:-1;
}
point p[MAXN];
int n;
inline bool chord(int a,int b){
	for(int i=0;i<n;i++){
		if(i!=a&&i!=b&&online(p[i],p[a],p[b])) return false;
		if(intersect(p[i],p[(i+1)%n],p[a],p[b])) return false;
	}
	point mid=(p[a]+p[b])/2;
	return inpolygon(mid,p,n)==1;
}
inline LL area(int a,int b,int c){
//s(a,b,c)*2
	return abs(cross(p[b]-p[a],p[c]-p[a]));
}
LL f[MAXN][MAXN];
inline LL max(LL a,LL b,LL c){
	LL t=a;
	if(b>t) t=b;
	if(c>t) t=c;
	return t;
}
inline LL min(LL a,LL b){
	return a<b?a:b;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%lld%lld",&p[i].x,&p[i].y);
			p[i].x*=2,p[i].y*=2;
		}
		for(int i=0;i<n-1;i++) f[i][i+1]=0;
		for(int _=2;_<n;_++)
			for(int i=0;i<n-_;i++){
				int j=i+_;
				f[i][j]=INF;
				if(chord(i,j)||(i==0&&j==n-1))
					for(int k=i+1;k<j;k++)
						f[i][j]=min(f[i][j],max(f[i][k],f[k][j],area(i,k,j)));
				}
		flag=true;
		flag=false;
		printf("%.1lf\n",(double)f[0][n-1]/8);
	}
	return 0;
}
