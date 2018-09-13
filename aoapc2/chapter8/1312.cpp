#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=200;
vector<int> x,y,h1;
bool map[MAXN][MAXN];
int n,a,b,xx[MAXN],yy[MAXN],h[MAXN];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);bool flag=false;
	while(t--){
		scanf("%d%d%d",&n,&a,&b);
		x.clear();x.push_back(0);x.push_back(a);
		y.clear();y.push_back(0);y.push_back(b);
		for(int i=0;i<n;i++){
			scanf("%d%d",&xx[i],&yy[i]);
			x.push_back(xx[i]);
			y.push_back(yy[i]);
		}
		sort(x.begin(),x.end());
		x.resize(unique(x.begin(),x.end())-x.begin());
		sort(y.begin(),y.end());
		y.resize(unique(y.begin(),y.end())-y.begin());
		memset(map,0,sizeof(map));
		for(int i=0;i<n;i++)
			map[lower_bound(x.begin(),x.end(),xx[i])-x.begin()][lower_bound(y.begin(),y.end(),yy[i])-y.begin()]=true; 
		int ans=0,ansx=0,ansy=0;
		for(int i=1;i<x.size();i++){
			h[0]=0;
			for(int j=1;j<y.size();j++)
				if(i==1) h[j]=x[i];
				else h[j]=(map[i-1][j]?0:h[j])+x[i]-x[i-1];
			h1.clear();h1.push_back(0);
			for(int j=1;j<y.size();j++){
				int cur=min(x[i],y[j]-y[h1.back()]);
				for(int k=h1.size()-1;k;k--)
					cur=max(cur,min(h[h1[k]],y[j]-y[h1[k-1]]));
				if(cur>ans){
					ans=cur;
					ansx=x[i]-cur;
					ansy=y[j]-cur;
				}
				while(!h1.empty()&&h[h1.back()]>=h[j]) h1.pop_back();
				h1.push_back(j);
			}	
		}
		if(flag)printf("\n");else flag=true;
		printf("%d %d %d\n",ansx,ansy,ans);
	}
	return 0;
}
