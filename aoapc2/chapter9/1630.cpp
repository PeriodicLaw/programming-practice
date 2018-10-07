#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MAXN=150;
char s[MAXN];
int r[MAXN][MAXN],f[MAXN][MAXN],g[MAXN][MAXN];
void print(int i,int j){
	if(g[i][j]==0)
		for(int k=i;k<=j;k++)
			printf("%c",s[k]);
	else if(g[i][j]>0){
		print(i,g[i][j]-1);
		print(g[i][j],j);
	}else{
		printf("%d(",(j-i+1)/(-g[i][j]));
		print(i,i-g[i][j]-1);
		printf(")");
	}
}
int digit(int x){
	int d=0;
	while(x)
		d++,x/=10;
	return d;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	while(!feof(stdin)){
		if(!gets(s)) break;
		int n=strlen(s);
		for(int i=0;i<n;i++)
			for(int j=1;i+j<=n;j++){
				r[i][j]=i+j-1;
				for(int k=j;i+k<n;k++)
					if(s[i+k]==s[i+k%j])
						r[i][j]++;
					else
						break;
			}
		for(int i=n-1;i>=0;i--)
			for(int j=i;j<n;j++){
				f[i][j]=j-i+1;g[i][j]=0;
				for(int k=i+1;k<=j;k++)
					if(f[i][k-1]+f[k][j]<f[i][j])
						f[i][j]=f[i][k-1]+f[k][j],
						g[i][j]=k;
				for(int k=1;k<j-i+1;k++)
					if((j-i+1)%k==0&&r[i][k]>=j)
						if(digit((j-i+1)/k)+2+f[i][i+k-1]<f[i][j])
							f[i][j]=digit((j-i+1)/k)+2+f[i][i+k-1],
							g[i][j]=-k;
			}
		print(0,n-1);
		printf("\n");
	}
	return 0;
}

