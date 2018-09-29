#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=150;
bool nosol,a[MAXN][MAXN],b[MAXN][MAXN];
int n,v[MAXN];
struct data{
	set<int> p;
	int d;
	data():d(0){
	}
	bool operator<(const data &a)const{
		return abs(d)>abs(a.d);
	}
};
vector<data> ve;
bool dfs(int i,int g,data &d){
	v[i]=g;
	d.d+=g;
	d.p.insert(i);
	for(int j=1;j<=n;j++)
		if(j!=i&&b[i][j])
			if((!v[j]&&dfs(j,-g,d))||v[j]==g)
				return true;
	return false;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int j;
			while(scanf("%d",&j)==1&&j)
				a[i][j]=true;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(!a[i][j]||!a[j][i])
					b[i][j]=b[j][i]=true;
		memset(v,0,sizeof(v));
		ve.clear();
		bool nosol=false;
		for(int i=1;i<=n;i++)
			if(!v[i]){
				ve.emplace_back();
				if(dfs(i,1,ve.back())){
					nosol=true;
					break;
				}
			}
		if(nosol){
			printf("No solution\n");
			if(t) printf("\n");
			continue;
		}
		sort(ve.begin(),ve.end());
		int sum=0;
		for(auto da:ve){
			if(sum*da.d>0){
				da.d=-da.d;
				for(auto i:da.p) v[i]=-v[i];
			}
			sum+=da.d;
		}
		int c1=0,c2=0;
		for(int i=1;i<=n;i++)
			if(v[i]==1) c1++;
			else if(v[i]==-1) c2++;
		printf("%d",c1);for(int i=1;i<=n;i++) if(v[i]==1) printf(" %d",i);printf("\n");
		printf("%d",c2);for(int i=1;i<=n;i++) if(v[i]==-1) printf(" %d",i);printf("\n");
		if(t) printf("\n");
	}
	return 0;
}
