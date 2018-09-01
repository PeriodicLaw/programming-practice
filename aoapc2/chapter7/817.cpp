#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,num[20],oper[20];
bool nosol;
void calc(){
	int s=0,i=0,t=1;
	while(i<n){
		int j=i,a=1;
		while(j<n){
			int k=j,b=0;
			do{
				b=b*10+num[k];
				k++;
			}while(k<n&&oper[k]==0);
			if(k>j+1&&num[j]==0) return;
			a*=b;
			j=k;
			if(j>=n||oper[j]!=3) break;
		}
		s+=t*a;
		i=j;
		if(i>=n) break;
		t=oper[i]==1?1:-1;
	}
	if(s!=2000) return;
	nosol=false;printf("  ");
	for(int i=0;i<n;i++){
		if(i&&oper[i]) printf(oper[i]==1?"+":oper[i]==2?"-":"*");
		printf("%d",num[i]);
	}
	printf("=\n");
}
void dfs(int d){
	if(d==n){
		calc();
		return;
	}
	for(int i=0;i<4;i++){
		oper[d]=i;
		dfs(d+1);
	}
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	char s[20];int count=0;
	while(gets(s),strcmp(s,"=")){
		printf("Problem %d\n",++count);
		memset(num,0,sizeof(num));
		memset(oper,0,sizeof(oper));
		n=strlen(s)-1;
		for(int i=0;i<n;i++) num[i]=s[i]-'0';
		nosol=true;
		if(strcmp(s,"2000="))
			dfs(1);
		if(nosol) printf("  IMPOSSIBLE\n");
	}
	return 0;
}
