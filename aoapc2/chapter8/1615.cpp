#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<utility>
#include<algorithm>
using namespace std;
const int MAXN=100000;
const double EPS=1e-8;
int x[MAXN],y[MAXN];
pair<double,double> s[MAXN];
bool cmp(decltype(s[0]) s1,decltype(s[0]) s2){
	if(fabs(s1.second-s2.second)<EPS)
		return s1.first>s2.first+EPS;
	else
		return s1.second<s2.second-EPS;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int m,d,n;
	while(scanf("%d%d%d",&m,&d,&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d%d",&x[i],&y[i]);
			double l=x[i]-sqrt(d*d-y[i]*y[i]),
				r=x[i]+sqrt(d*d-y[i]*y[i]);
			if(l<EPS) l=0;
			if(r>m-EPS) r=m;
			s[i].first=l,s[i].second=r;
		}
		sort(s,s+n,cmp);
		int ans=0;
		for(int i=0;i<n;){
			++ans;
			int j=i;
			while(j<n&&s[j].first<s[i].second+EPS) j++;
			i=j;
		}
		printf("%d\n",ans);
	}
	return 0;
}
