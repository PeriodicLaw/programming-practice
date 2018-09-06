#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=1000000;
int a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int z;scanf("%d",&z);
	while(z--){
		int n;scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(int i=0;i<n;i++) scanf("%d",&b[i]);
		c[0]=b[0];
		for(int i=1;i<n;i++)
			if(a[i]>c[i-1])
				c[i]=a[i];
			else if(b[i]<c[i-1])
				c[i]=b[i];
			else
				c[i]=c[i-1];
		d[n-1]=b[n-1];
		for(int i=n-2;i>=0;i--)
			if(a[i]>d[i+1])
				d[i]=a[i];
			else if(b[i]<d[i+1])
				d[i]=b[i];
			else
				d[i]=d[i+1];
		int ans=0;
		for(int i=0;i<n;i++)
			ans+=(c[i]<d[i]?c[i]:d[i])-a[i];
		printf("%d\n",ans);
	}
	return 0;
}

