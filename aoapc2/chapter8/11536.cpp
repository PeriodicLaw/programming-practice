#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MAXN=1000100,MAXK=120;
int x[MAXN],c[MAXK];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n,m,k;scanf("%d%d%d",&n,&m,&k);
		x[0]=1,x[1]=2,x[2]=3;
		for(int i=3;i<n;i++) x[i]=(x[i-1]+x[i-2]+x[i-3])%m+1;
		int l=0,r=0,ans=-1;
		memset(c,0,sizeof(c));
		for(int i=1;i<=k;i++)
			while(!c[i])
				if(r==n)
					goto label;
				else{
					if(x[r]<=k) c[x[r]]++;
					r++;
				}
		ans=r;
		while(true){
			if(x[l]<=k){
				c[x[l]]--;
				while(!c[x[l]])
					if(r==n)
						goto label;
					else{
						if(x[r]<=k) c[x[r]]++;
						r++;
					}
			}
			l++;
			if(r-l<ans) ans=r-l; 
		}
		label:printf("Case %d: ",tt);
		if(ans==-1) printf("sequence nai\n"); else printf("%d\n",ans);
	}
	return 0;
}
