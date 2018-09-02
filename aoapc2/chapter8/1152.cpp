#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN=4010;
long long a[MAXN],b[MAXN],c[MAXN],d[MAXN],f[MAXN*MAXN];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lld%lld%lld%lld",&a[i],&b[i],&c[i],&d[i]);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				f[i*n+j]=a[i]+b[j];
		sort(f,f+n*n);
		unsigned long long ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				long long g=-c[i]-d[j];
				ans+=upper_bound(f,f+n*n,g)-lower_bound(f,f+n*n,g);
			}
		printf("%llu\n",ans);
		if(t) printf("\n");
	}
	return 0;
}

