#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=70,MAXY=3000;
pair<int,int> a[MAXN];
int f[MAXN][MAXY];
bool cmp(const pair<int,int> &a,const pair<int,int> &b){
	return a.second*b.first>a.first*b.second;
} 
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n,m;scanf("%d%d",&n,&m);
		int sy=0;
		for(int i=0;i<n;i++)
			scanf("%d%d",&a[i].first,&a[i].second),
			sy+=a[i].second;
		sort(a,a+n,cmp);
		memset(f,0xF0,sizeof(f));
		f[0][0]=0;
		for(int i=0;i<n;i++){
			for(int j=min(i+1,m);j;j--)
				for(int y=sy;y>=a[i].second;y--)
						f[j][y]=max(f[j][y],f[j-1][y-a[i].second]-a[i].first*a[i].second+2*a[i].first*y);
		}
		int ans=0;
		for(int y=0;y<=sy;y++)
			if(f[m][y]>ans)
				ans=f[m][y];
		printf("Case %d: %d\n",tt,ans);
	}
	return 0;
}
