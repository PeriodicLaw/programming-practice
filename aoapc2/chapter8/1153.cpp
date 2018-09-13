#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct data{
	int q,d;
	bool operator<(const data &x)const{
		if(d==x.d)
			return q<x.q;
		else
			return d<x.d;
	}
}a[800010];
int b[800010];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&a[i].q,&a[i].d);
		sort(a,a+n);
		int len=0;
		int h=0,m=0;
		for(int i=0;i<n;i++)
			if(len+a[i].q<=a[i].d){
				m++;
				len+=a[i].q;
				b[h++]=a[i].q;
				push_heap(b,b+h);
			}else if(h&&a[i].q<b[0]){
				len+=a[i].q-b[0];
				pop_heap(b,b+h);
				b[h-1]=a[i].q;
				push_heap(b,b+h);
			}
		printf("%d\n",m);
		if(t) printf("\n");
	} 
	return 0;
}