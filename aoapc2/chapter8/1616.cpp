#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=100010;
struct data{
	int l,r;
	bool operator<(const data &x)const{
		return r<x.r;
	}
}a[MAXN];
int gcd(int x,int y){
	if(y==0) return x;
	else if(x<y) return gcd(x,y%x);
	else return gcd(y,x%y);
}
struct rat{
	int p,q;
	rat(int x,int y){
		int g=gcd(x,y);
		p=x/g,q=y/g;
	}
	bool operator<(const rat &x)const{
		return (LL)p*x.q<(LL)q*x.p;
	}
	bool operator==(const rat &x)const{
		return (LL)p*x.q==(LL)q*x.p;
	}
	bool operator<=(const rat &x)const{
		return (LL)p*x.q<=(LL)q*x.p;
	}
};
int mq[MAXN];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d%d",&a[i].l,&a[i].r);
		sort(a,a+n);
		int qf=0,qb=0;
		rat ans(a[0].r-a[0].l,1);
		for(int i=0;i<n;i++){
			while(qb>qf+1){
				rat k1(a[i].l-a[mq[qb-1]].l,i-mq[qb-1]);
				rat k2(a[i].l-a[mq[qb-2]].l,i-mq[qb-2]);
				if(k2<k1) qb--;
				else break;
			}
			mq[qb++]=i;
			rat k(a[i].r-a[mq[qf]].l,i+1-mq[qf]);
			while(qb>qf+1){
				rat k0(a[i].r-a[mq[qf+1]].l,i+1-mq[qf+1]);
				if(k0<k){
					k=k0;
					qf++;
				}else break;
			}
			if(k<ans) ans=k;
		}
		printf("%d/%d\n",ans.p,ans.q);
	}
	return 0;
}