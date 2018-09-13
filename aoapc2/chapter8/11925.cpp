#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=350;
int n,m,a[MAXN],b[MAXN*MAXN*2];
int pos(int x){
	for(int i=0;i<n;i++)
		if(a[i]==x)
			return i;
}
void rotate(int x){
	x%=n;
	int t[MAXN];
	for(int i=0;i<x;i++) t[i]=a[n-x+i];
	for(int i=n-1;i>=x;i--) a[i]=a[i-x];
	for(int i=0;i<x;i++) a[i]=t[i];
	for(int i=m;i<m+x;i++) b[i]=2;
	m+=x;
}
void swap(){
	int t=a[0];a[0]=a[1];a[1]=t;
	b[m++]=1;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	while(scanf("%d",&n)==1&&n){
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		m=0;
		for(int i=2;i<=n;i++){
			rotate(n-pos(i)+1);
			while(a[0]!=i-1)
				swap(),rotate(1);
		}
		rotate(n-pos(1));
		for(int i=m-1;i>=0;i--) printf("%d",b[i]);
		printf("\n");
	}
	return 0;
}

