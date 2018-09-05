#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int a[100010];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		int l=0,r=n-1,m=0;
		while(l<=r){
			if(l==r){
				m++;
				break;
			}
			if(a[l]+a[r]<=k){
				m++;
				l++;
				r--;
			}else{
				m++;
				r--;
			}
		}
		printf("%d\n",m);
		if(t) printf("\n");
	}
	return 0;
}

