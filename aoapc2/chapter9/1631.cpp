#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=1010,INF=1000000;
int n,f[MAXN][10][10],a[MAXN],b[MAXN];
bool read(int a[]){
	char s[MAXN];
	if(scanf("%s",s)==EOF) return false;
	n=strlen(s);
	for(int i=0;i<n;i++)
		a[i]=s[i]-'0';
	return true;
}
int dp(int n,int x,int y){
	if(n==1)
		return min((y-b[0]+10)%10,(b[0]-y+10)%10);
	if(f[n][x][y]>=0) return f[n][x][y];
	if(n==2){
		int d=(b[1]-y+10)%10,ans=INF;
		for(int i=0;i<=d;i++){
			int t=dp(1,-1,(x+i)%10)+d;
			if(t<ans) ans=t;
		}
		d=(y-b[1]+10)%10;
		for(int i=0;i<=d;i++){
			int t=dp(1,-1,(x-i+10)%10)+d;
			if(t<ans) ans=t;
		}
		return f[n][x][y]=ans;
	}
	int d=(b[n-1]-y+10)%10,ans=INF;
	for(int i=0;i<=d;i++)
		for(int j=0;i+j<=d;j++){
			int t=dp(n-1,(a[n-3]+i)%10,(x+i+j)%10)+d;
			if(t<ans) ans=t;
		}
	d=(y-b[n-1]+10)%10;
	for(int i=0;i<=d;i++)
		for(int j=0;i+j<=d;j++){
			int t=dp(n-1,(a[n-3]-i+10)%10,(x-i-j+20)%10)+d;
			if(t<ans) ans=t;
		}
	return f[n][x][y]=ans;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	while(read(a)&&read(b)){
		for(int i=0;i<=n;i++)
			for(int j=0;j<10;j++)
				for(int k=0;k<10;k++)
					f[i][j][k]=-1;
		if(n==1)
			printf("%d\n",dp(n,-1,a[n-1]));
		else
			printf("%d\n",dp(n,a[n-2],a[n-1]));
	}
	return 0;
}
