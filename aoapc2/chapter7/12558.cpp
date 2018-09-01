#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a,b,maxd;
bool ban[1010];
long long ans[1000],now[1000];
long long gcd(long long x,long long y){
	if(x==0) return y;
	if(x>y)
		int t=x,x=y,y=t;
	return gcd(y%x,x);
}
bool opti(int d){
	for(int i=d;i>=0;i--)
		if(ans[i]<now[i]) return false;
		else if(ans[i]>now[i]) return true;
	return false;
}
void solve(long long a,long long b,long long m,int d){
	long long g=gcd(a,b);a/=g,b/=g;
	if(d==maxd){
		if(a==1&&b>m){
			if(b<=1000&&ban[b]) return;
			now[d]=b;
			if(!ans[0]||opti(d)){
				for(int i=0;i<=d;i++)
					ans[i]=now[i];
				return;
			}
		}
	}else{
		long long rd=maxd-d+1,min=((b/a>m)?b/a:m)+1,max=rd*b/a;
		if(ans[0]&&max>ans[maxd]) max=ans[maxd];
		//a/b<=rd/n,n*a<=rd*b;a/b>1/n,n*a>b
		for(long long n=min;n<=max;n++){
			if(n<=1000&&ban[n]) continue;
			now[d]=n;
			solve(a*n-b,b*n,n,d+1);//a/b-1/n
		}
	}
	return;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t,k;scanf("%d",&t);
	for(int it=1;it<=t;it++){
		memset(ans,0,sizeof(ans));
		memset(ban,false,sizeof(ban));
		scanf("%d%d%d",&a,&b,&k);
		for(int i=0;i<k;i++){
			int t;scanf("%d",&t);ban[t]=true;
		}
		maxd=0;
		while(true){
			solve(a,b,0,0);
			if(ans[0]){
				printf("Case %d: %d/%d",it,a,b);
				for(int i=0;i<=maxd;i++){
					if(i==0) printf("="); else printf("+");
					printf("1/%lld",ans[i]);
				}
				printf("\n");
				break;
			}
			maxd++;
		}
	}
	return 0;
}
