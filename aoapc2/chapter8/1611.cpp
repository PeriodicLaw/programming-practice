#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=10010;
int a[MAXN],p[MAXN],n,m,l[2*MAXN],r[2*MAXN];
void flip(int x,int y){
	l[m]=x,r[m]=y,++m;
	for(int i=1;i<=n;i++)
		if(p[i]>=x&&p[i]<=(y+x)/2)
			p[i]+=(y+1-x)/2;
		else if(p[i]>(y+x)/2&&p[i]<=y)
			p[i]-=(y+1-x)/2;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			p[a[i]]=i;
		}
		m=0;
		for(int i=1;i<=n;i++){
			if(p[i]>(n+i)/2)
				if((n+1-i)%2)
					flip(i+1,n);
				else
					flip(i,n);
			if(p[i]>i) flip(i,2*p[i]-i-1);
		}
		printf("%d\n",m);
		for(int i=0;i<m;i++) printf("%d %d\n",l[i],r[i]);
	}
	return 0;
}

