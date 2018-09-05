#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=510;
int n,m,a[MAXN],b[MAXN];
int assign(long long k){
	int s=0,j=0;
	for(int i=n-1;i>=0;i--){
		if(s+a[i]>k||i+j<=m-2){
			b[j]=i+1;
			j++;
			s=a[i];
		}else
			s+=a[i];
	}
	return j+1;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		long long l=0,r=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i]>l) l=a[i];
			r+=a[i];
		}
		while(l<r){
			long long mid=(l+r)/2;
			if(assign(mid)<=m)
				r=mid;
			else
				l=mid+1;
		}
		assign(l);
		for(int i=0,j=m-2;i<n;i++){
			if(i) printf(" ");
			if(j>=0&&b[j]==i){
				printf("/ ");
				j--;
			}
			printf("%d",a[i]);
		}
		printf("\n");
	}
	return 0;
}

