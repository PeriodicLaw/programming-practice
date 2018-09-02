#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct point{
	int x,y,r;
};
point base;
inline bool operator<(const point &a,const point &b){
	if(b.x==base.x) return true;
	if(a.x==base.x) return false;
	if((b.x-base.x)*(a.x-base.x)>0)
		return (a.y-base.y)*(b.x-base.x)<(b.y-base.y)*(a.x-base.x);
	else
		return (a.y-base.y)*(b.x-base.x)>(b.y-base.y)*(a.x-base.x);
}
inline bool operator==(const point &a,const point &b){
	return (a.y-base.y)*(b.x-base.x)==(b.y-base.y)*(a.x-base.x);
}
inline bool atleft(const point &a){
	return (a.x>base.x)||((a.x==base.x)&&(a.y>base.y));
}
const int MAXN=1010;
point acm[MAXN],myacm[MAXN];
int n;
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	while(scanf("%d",&n)==1&&n){
		for(int i=0;i<n;i++)
			scanf("%d%d%d",&acm[i].x,&acm[i].y,&acm[i].r);
		int ans=0;
		for(int i=0;i<n;i++){
			base=acm[i];
			for(int j=0;j<n;j++)
				if(j<i)
					myacm[j]=acm[j];
				else if(j>i)
					myacm[j-1]=acm[j];
			sort(myacm,myacm+n-1);
			int l[2]={0},r[2]={0};
			l[base.r]=r[base.r]=1;
			for(int j=0;j<n-1;j++)
				if(atleft(myacm[j]))
					l[myacm[j].r]++;
				else
					r[myacm[j].r]++;
			for(int j=0;j<n-1;){
				int k;
				for(k=j;k<n-1&&myacm[j]==myacm[k];k++)
					if(atleft(myacm[k])) r[myacm[k].r]++;
					else l[myacm[k].r]++;
				if(l[0]+r[1]>ans) ans=l[0]+r[1];
				if(l[1]+r[0]>ans) ans=l[1]+r[0];
				for(int kk=j;kk<k;kk++)
					if(atleft(myacm[kk])) l[myacm[kk].r]--;
					else r[myacm[kk].r]--;
				j=k;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
