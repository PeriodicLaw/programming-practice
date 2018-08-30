#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=7,power2[MAXN]={1,2,4,8,16,32,64};
int n,m,x[MAXN];
char s[1<<MAXN+20],c[MAXN+20];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int count=0;
    while(scanf("%d",&n)==1&&n){
    	for(int i=1;i<=n;i++){
    		int t;scanf(" x%d",&t);
    		x[t-1]=power2[n-i];
		}
		scanf(" %s",s);
		printf("S-Tree #%d:\n",++count);
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf(" %s",c);
			int ans=0;
			for(int j=0;j<n;j++)
				if(c[j]!='0')
					ans+=x[j];
			printf("%c",s[ans]);
		}
		printf("\n\n");
	}
	return 0;
}

