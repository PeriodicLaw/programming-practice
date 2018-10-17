#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=510,INF=1000000;
int a[MAXN],m[MAXN][MAXN],t[MAXN][MAXN],g[MAXN][MAXN],f[MAXN];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int n;
	while(scanf("%d",&n)==1){
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		memset(t,0,sizeof(t));
		for(int i=0;i<n;i++){
			set<int> s;
			for(int j=i;j<n;j++)
				if(s.count(a[j]))
					break;
				else{
					s.insert(a[j]);
					m[i][j]=*(s.begin());
					t[i][j]=1;
					int c=1;
					while(s.count(c)) c++;
					if(c==j-i+2) t[i][j]=2;
				}
		}
		for(int i=n-1;i>=0;i--){
			vector<int> v;
			for(int j=i;j<n;j++)
				if(t[i][j]){
					v.insert(upper_bound(v.begin(),v.end(),a[j]),a[j]);
					if(j==i){
						g[i][i]=0;
						continue;
					}
					g[i][j]=INF;
					for(int k=i;k<j;k++){
						int x=j-i+1-abs(upper_bound(v.begin(),v.end(),m[i][k])-upper_bound(v.begin(),v.end(),m[k+1][j]));
						if(g[i][k]+g[k+1][j]+x<g[i][j])
							g[i][j]=g[i][k]+g[k+1][j]+x;
					}
				}
		}
		f[0]=0;
		for(int i=1;i<=n;i++){
			f[i]=INF;
			for(int j=0;j<i;j++)
				if(t[j][i-1]==2&&f[j]+g[j][i-1]<f[i])
					f[i]=f[j]+g[j][i-1];
		}
		if(f[n]>=INF) printf("impossible\n");
		else printf("%d\n",f[n]);
	}
	return 0;
}
