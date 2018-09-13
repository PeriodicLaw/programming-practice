#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=100100;
struct data{
	int l,r;
	bool operator<(const data &x){
		if(r==x.r)
			return l<x.l;
		else
			return r<x.r;
	}
}a[MAXN];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d%d",&a[i].l,&a[i].r);
		sort(a,a+n);
		int l=-1,r=-1,ans=-1;
		for(int i=0;i<n;i++)
			if(a[i].l<=r||a[i].r<=l){
				l=max(l+1,a[i].l+1);
				r=min(r+1,a[i].r);
			}else{
				l=a[i].l+1;
				r=a[i].r;
				ans++;
			}
		printf("%d\n",ans);
	}
	return 0;
}
