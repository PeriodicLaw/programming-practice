#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MAXN=500,MAXK=10;
const LL MOD=1000000007;
LL f[MAXN][1<<MAXK];
bool palindromic(int x,int l){
	int a[MAXK*2];
	for(int i=0;i<l;i++)
		a[i]=x&1,x>>=1;
	for(int i=0;i<l/2;i++)
		if(a[i]!=a[l-i-1])
			return false;
	return true;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		int n,k;scanf("%d%d",&n,&k);
		if(n<k){
			printf("%d\n",(1<<n)%MOD);
			continue;
		}
		memset(f,0,sizeof(f));
		for(int i=0;i<(1<<k);i++)
			f[k][i]=palindromic(i,k)?0:1;
		for(int i=k;i<n;i++)
			for(int j=0;j<(1<<k);j++){
				if(!palindromic(j*2,k)&&!palindromic(j*2,k+1))
					f[i+1][(j*2)%(1<<k)]=(f[i+1][(j*2)%(1<<k)]+f[i][j])%MOD;
				if(!palindromic(j*2+1,k)&&!palindromic(j*2+1,k+1))
					f[i+1][(j*2+1)%(1<<k)]=(f[i+1][(j*2+1)%(1<<k)]+f[i][j])%MOD;
			}
		LL ans=0;
		for(int i=0;i<(1<<k);i++)
			ans=(ans+f[n][i])%MOD;
		printf("%lld\n",ans);
	}
	return 0;
}
