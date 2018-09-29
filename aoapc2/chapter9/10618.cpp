#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MAXN=100,INF=1<<27;
struct data{
	int f,h;
	data *g;
}dp[MAXN][4][4];
void update(data &t,data &s,int e,int m){
	int e1=s.f+((m==0)?0:(s.h!=m)?1:e);
	if(e1<t.f){
		t.f=e1;
		t.g=&s;
		t.h=m;
	}
}
void print(data &t){
	if(!t.g) return;
	print(*t.g);
	if(t.h==0) printf(".");
	else if(t.h==1) printf("L");
	else if(t.h==2) printf("R");
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	char s[MAXN];
	while(true){
		gets(s);
		if(s[0]=='#') break;
		int n=strlen(s);
		for(int i=0;i<=n;i++) for(int a=0;a<4;a++) for(int b=0;b<4;b++) dp[i][a][b].f=INF;
		dp[0][0][2]={0,0,nullptr};
		for(int i=0;i<n;i++)
			for(int a=0;a<4;a++)
				for(int b=0;b<4;b++) if(a!=b)
					if(dp[i][a][b].f<INF){
						if(s[i]=='.'){
							update(dp[i+1][a][b],dp[i][a][b],3,0);
							if(a==0){
								update(dp[i+1][1][b],dp[i][a][b],5,1);
								update(dp[i+1][3][b],dp[i][a][b],5,1);
								if(b==1||b==3) update(dp[i+1][2][b],dp[i][a][b],7,1);
							}else if(a==2){
								update(dp[i+1][0][b],dp[i][a][b],7,1);
								update(dp[i+1][1][b],dp[i][a][b],5,1);
								update(dp[i+1][3][b],dp[i][a][b],5,1);
							}else if((a==1||a==3)&&b!=0){
								update(dp[i+1][0][b],dp[i][a][b],5,1);
								update(dp[i+1][4-a][b],dp[i][a][b],7,1);
								if(b==1||b==3) update(dp[i+1][2][b],dp[i][a][b],5,1);
							}
							if(b==2){
								update(dp[i+1][a][1],dp[i][a][b],5,2);
								update(dp[i+1][a][3],dp[i][a][b],5,2);
								if(a==1||a==3) update(dp[i+1][a][0],dp[i][a][b],7,2);
							}else if(b==0){
								update(dp[i+1][a][1],dp[i][a][b],5,2);
								update(dp[i+1][a][2],dp[i][a][b],7,2);
								update(dp[i+1][a][3],dp[i][a][b],5,2);
							}else if((b==1||b==3)&&a!=2){
								update(dp[i+1][a][2],dp[i][a][b],5,2);
								update(dp[i+1][a][4-b],dp[i][a][b],7,2);
								if(a==1||a==3) update(dp[i+1][a][0],dp[i][a][b],5,2);
							}
						}else if(s[i]=='L'){
							if(a==0) update(dp[i+1][a][b],dp[i][a][b],3,1);
							else if(a==2) update(dp[i+1][0][b],dp[i][a][b],7,1);
							else if((a==1||a==3)&&b!=0) update(dp[i+1][0][b],dp[i][a][b],5,1);
							if(b==0) update(dp[i+1][a][b],dp[i][a][b],3,2);
							else if(b==2&&(a==1||a==3)) update(dp[i+1][a][0],dp[i][a][b],7,2);
							else if((b==1||b==3)&&a!=2) update(dp[i+1][a][0],dp[i][a][b],5,2);
						}else if(s[i]=='U'){
							if(a==1) update(dp[i+1][a][b],dp[i][a][b],3,1);
							else if(a==0||a==2) update(dp[i+1][1][b],dp[i][a][b],5,1);
							else if(a==3&&b!=0) update(dp[i+1][1][b],dp[i][a][b],7,1);
							if(b==1) update(dp[i+1][a][b],dp[i][a][b],3,2);
							else if(b==0||b==2) update(dp[i+1][a][1],dp[i][a][b],5,2);
							else if(b==3&&a!=2) update(dp[i+1][a][1],dp[i][a][b],7,2);
						}else if(s[i]=='R'){
							if(a==2) update(dp[i+1][a][b],dp[i][a][b],3,1);
							else if(a==0&&(b==1||b==3)) update(dp[i+1][2][b],dp[i][a][b],7,1);
							else if((a==1||a==3)&&b!=0) update(dp[i+1][2][b],dp[i][a][b],5,1);
							if(b==2) update(dp[i+1][a][b],dp[i][a][b],3,2);
							else if(b==0) update(dp[i+1][a][2],dp[i][a][b],5,2);
							else if((b==1||b==3)&&a!=2) update(dp[i+1][a][2],dp[i][a][b],5,2);
						}else if(s[i]=='D'){
							if(a==3) update(dp[i+1][a][b],dp[i][a][b],3,1);
							else if(a==0||a==2) update(dp[i+1][3][b],dp[i][a][b],5,1);
							else if(a==1&&b!=0) update(dp[i+1][3][b],dp[i][a][b],7,1);
							if(b==3) update(dp[i+1][a][b],dp[i][a][b],3,2);
							else if(b==0||b==2) update(dp[i+1][a][3],dp[i][a][b],5,2);
							else if(b==1&&a!=2) update(dp[i+1][a][3],dp[i][a][b],7,2);
						}
					}
		data &ans=dp[n][0][1];
		for(int a=0;a<4;a++)
			for(int b=0;b<4;b++)
				if(a!=b&&dp[n][a][b].f<ans.f)
					ans=dp[n][a][b];
		print(ans);
		printf("\n");
	}
	return 0;
}
