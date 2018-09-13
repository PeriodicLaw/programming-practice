#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MAXN=1000,INF=10000000;
int a[MAXN],b[MAXN],p[MAXN],v[MAXN];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int n;
	while(scanf("%d",&n)==1&&n){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			a[i]--;
			p[a[i]]=i;
		}
		int ans=INF;
		for(int i=0;i<2*n;i++){
			if(i<n)
				for(int j=0;j<n;j++)
					b[j]=(i+j)%n;
			else	
				for(int j=0;j<n;j++)
					b[j]=(i-j+n)%n;
			for(int j=0;j<n;j++) v[j]=0;
			int cur=0;
			for(int j=0;j<n;j++)
				if(!v[j]){
					int k,count=0;
					for(k=p[b[j]];k!=j;k=p[b[k]])
						count++,v[k]=1;
					cur+=count;
				}
			if(cur<ans) ans=cur;
		}
		printf("%d\n",ans);
	}
	return 0;
}
