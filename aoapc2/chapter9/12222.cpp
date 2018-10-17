#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<utility>
using namespace std;
typedef long long LL;
const int MAXN=220;
int f[MAXN][MAXN][2];
pair<int,int> a[MAXN],b[MAXN];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int c;scanf("%d",&c);
	while(c--){
		int n;scanf("%d",&n);
		int na=0,nb=0;
		for(int i=0;i<n;i++){
			char c;scanf(" %c",&c);
			if(c=='A'){
				scanf("%d%d",&a[na].first,&a[na].second);
				na++;
			}else{
				scanf("%d%d",&b[nb].first,&b[nb].second);
				nb++;
			}
		}
		memset(f,0x70,sizeof(f));
		f[0][0][0]=f[0][0][1]=0;
		for(int i=0;i<=na;i++)
			for(int j=0;j<=nb;j++){
				int p=f[i][j][1],q=f[i][j][1];
				for(int k=i;k<na;k++){
					if(a[k].first>p) p=a[k].first;
					if(p+a[k].second>q) q=p+a[k].second;
					if(q<f[k+1][j][0]) f[k+1][j][0]=q;
					p+=10,q+=10;
				}
				p=q=f[i][j][0];
				for(int k=j;k<nb;k++){
					if(b[k].first>p) p=b[k].first;
					if(p+b[k].second>q) q=p+b[k].second;
					if(q<f[i][k+1][1]) f[i][k+1][1]=q;
					p+=10,q+=10;
				}
			}
		printf("%d\n",f[na][nb][0]<f[na][nb][1]?f[na][nb][0]:f[na][nb][1]);
	}
	return 0;
}
