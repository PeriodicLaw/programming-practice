#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN=100010;
char a[MAXN];
int h[MAXN];
bool cmp(const int &x,const int &y){
	return (a[x]<a[y])||((a[x]==a[y])&&(x>y));
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int n,d;
	while(scanf("%d%d ",&n,&d)==2&&n&&d){
		gets(a);
		int l=-1,n=strlen(a),m=d;
		for(int i=0;i<d;i++)
			h[i]=i;
		make_heap(h,h+m,cmp);
		for(int i=d;i<n;i++){
			h[m++]=i;
			push_heap(h,h+m,cmp);
			while(h[0]<=l)
				pop_heap(h,h+m,cmp),--m;
			putchar(a[h[0]]);
			l=h[0];
		}
		putchar('\n');
	}
	return 0;
}

