#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
using namespace std;
const int MAXN=200010;
map<int,int> h;
int a[MAXN],f[MAXN],g[MAXN];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int z;scanf("%d",&z);
	while(z--){
		int n;scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		f[n-1]=1;for(int i=n-2;i>=0;i--) f[i]=(a[i+1]>a[i])?f[i+1]+1:1;
		int ans=1;h.clear();
		g[0]=1;h.insert(make_pair(a[0],0));
		for(int i=1;i<n;i++){
			g[i]=(a[i-1]<a[i])?g[i-1]+1:1;
			auto it=h.lower_bound(a[i]);
			if(it==h.begin()) ans=f[i]>ans?f[i]:ans;
			else ans=(f[i]+g[(--it)->second])>ans?(f[i]+g[it->second]):ans;
			it=h.upper_bound(a[i]);
			if(it!=h.begin()&&g[(--it)->second]>g[i]) continue;
			h.insert(make_pair(a[i],i));
			while(it=h.upper_bound(a[i]),it!=h.end()&&g[it->second]<g[i])
				h.erase(it);
		}
		printf("%d\n",ans);
	}
	return 0;
}
