#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MAXN=17,MAXL=120,INF=100000;
int n,f[1<<MAXN][MAXN*2],g[MAXN*2][MAXN*2];
char s[MAXN*2][MAXL];
void my_strrev(char *s){
	int l=strlen(s);
	for(int i=0;i<l/2;i++){
		char t=s[l-i-1];
		s[l-i-1]=s[i];
		s[i]=t;
	}
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int n;
	while(scanf("%d ",&n)==1&&n){
		for(int i=0;i<n;i++)
			gets(s[i]);
		for(int i=0;i<n;){
			bool ok=false;
			for(int j=0;j<n;j++)
				if(i!=j&&strstr(s[j],s[i])){
					for(int k=i+1;k<n;k++)
						strcpy(s[k-1],s[k]);
					ok=true;
					break;
				}
			if(!ok){
				char s1[MAXL];
				strcpy(s1,s[i]);
				my_strrev(s1);
				for(int j=0;j<n;j++)
					if(i!=j&&strstr(s[j],s1)){
						for(int k=i+1;k<n;k++)
							strcpy(s[k-1],s[k]);
						ok=true;
						break;
					}
			}
			if(ok) n--;
			else i++;
		}
		if(n==1){
			int m=strlen(s[0]);
			for(int i=1;i<=m;i++){
				bool ok=true;
				for(int j=i;j<m;j++)
					if(s[0][j]!=s[0][j%i]){
						ok=false;
						break;
					}
				if(ok){
					printf("%d\n",i==1?2:i);
					break;
				}
			}
			continue;
		}
		int len=0;
		for(int i=0;i<n;i++) len+=strlen(s[i]);
		for(int i=0;i<n;i++){
			strcpy(s[i+n],s[i]);
			my_strrev(s[i+n]);
		}
		for(int i=0;i<2*n;i++)
			for(int j=0;j<2*n;j++)
				if(i!=j){
					g[i][j]=0;
					for(int k=strlen(s[i]);k>=1;k--)
						if(strstr(s[j],s[i]+strlen(s[i])-k)==s[j]){
							g[i][j]=k;
							break;
						}
				}
		memset(f,0,sizeof(f));
		for(int i=1;i<(1<<n);i++) for(int j=0;j<2*n;j++) f[i][j]=INF;
		f[1][0]=strlen(s[0]);
		for(int i=1;i<(1<<n);i++)
			for(int j=0;j<2*n;j++)
				if(f[i][j]<INF)
					for(int k=1;k<2*n;k++)
						if(k!=n&&!(i&(1<<(k%n))))
							if(f[i][j]+strlen(s[k])-g[j][k]<f[i|(1<<(k%n))][k])
								f[i|(1<<(k%n))][k]=f[i][j]+strlen(s[k])-g[j][k];
		int ans=INF;
		for(int i=0;i<2*n;i++)
			if(i!=n&&f[(1<<n)-1][i]-g[i][0]<ans)
				ans=f[(1<<n)-1][i]-g[i][0];
		printf("%d\n",(ans<=1)?2:ans);
	}
	return 0;
}
