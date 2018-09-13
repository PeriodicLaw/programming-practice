#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
using namespace std;
typedef long long LL;
const int MAXN=1010;
int n,m,a[MAXN][MAXN],h[MAXN];
pair<int,int> s[MAXN];
map<int,int> ans;
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		ans.clear();
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf(" ");
			for(int j=0;j<m;j++){
				char c=getchar();
				a[i][j]=c=='.';
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				if(a[i][j])
					h[j]=(i==0)?1:h[j]+1;
				else
					h[j]=0;
			int st=0;
			for(int j=0;j<m;j++){
				int t=j;
				while(st&&s[st-1].second>h[j])
					t=s[st-1].first,--st;
				if(h[j]==0) continue;
				if(!st||s[st-1].second-s[st-1].first<h[j]-t)
					s[st].first=t,s[st].second=h[j],++st;
				ans[2*(j-s[st-1].first+s[st-1].second+1)]++;
			}
		}
		for(auto p:ans)
			printf("%d x %d\n",p.second,p.first);
	}
	return 0;
}