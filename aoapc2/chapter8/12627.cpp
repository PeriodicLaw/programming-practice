#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
long long p2[31],p3[31];
long long f(int k,int n){
	if(k==0)
		return n?1:0;
	if(n<=p2[k-1])
		return 2*f(k-1,n);
	else
		return f(k-1,n-p2[k-1])+2*p3[k-1];
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	p2[0]=p3[0]=1;
	for(int i=1;i<=30;i++)
		p2[i]=p2[i-1]*2,p3[i]=p3[i-1]*3;
	int t;scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int k,a,b;
		scanf("%d%d%d",&k,&a,&b);
		printf("Case %d: %lld\n",tt,f(k,b)-f(k,a-1));
	}
	return 0;
}

