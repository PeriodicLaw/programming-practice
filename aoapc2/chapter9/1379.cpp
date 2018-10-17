#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<tuple>
#include<map>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=300,MAXM=150;
pair<int,int> p[MAXM][MAXN];
map<tuple<int,int,int,int>,int> f[2];
inline bool cmp(pair<int,int> x,pair<int,int> y){
	return x.first>y.first;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t,n,m,g;scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&g);
		g+=10;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&p[i][j].first);
				p[i][j].second=j+1;
			}
			sort(p[i],p[i]+n,cmp);
		}
		f[0].clear();
		f[0].insert(make_pair(make_tuple(0,0,0,0),0));
		for(int i=1;i<=g;i++){
			f[i%2].clear();
			int d;scanf("%d",&d);
			if(d==0)
				for(auto j:f[(i+1)%2]){
					auto t=make_tuple(get<1>(j.first),get<2>(j.first),get<3>(j.first),0);
					auto it=f[i%2].find(t);
					if(it==f[i%2].end())
						f[i%2].insert(make_pair(t,j.second));
					else if(it->second<j.second)
						it->second=j.second;
				}
			else
				for(auto j:f[(i+1)%2])
					for(int k=0;k<5;k++)
						if(get<0>(j.first)!=p[d-1][k].second&&get<1>(j.first)!=p[d-1][k].second&&get<2>(j.first)!=p[d-1][k].second&&get<3>(j.first)!=p[d-1][k].second){
							auto t=make_tuple(get<1>(j.first),get<2>(j.first),get<3>(j.first),p[d-1][k].second);
							auto it=f[i%2].find(t);
							if(it==f[i%2].end())
								f[i%2].insert(make_pair(t,j.second+p[d-1][k].first));
							else if(it->second<j.second+p[d-1][k].first)
								it->second=j.second+p[d-1][k].first;
						}
		}
		int ans=0;
		for(auto j:f[g%2])
			if(j.second>ans)
				ans=j.second;
		printf("%.2lf\n",(double)ans/100);
	}
	return 0;
}
