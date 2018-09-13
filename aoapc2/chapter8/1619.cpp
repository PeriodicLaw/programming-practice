#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=100100;
int a[MAXN],l[MAXN],r[MAXN];
map<int,int> m;
LL s[MAXN];
bool cmp(int x,int y){
	return a[x]<a[y];
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int n;bool flag=false;
	while(scanf("%d",&n)!=EOF){
		s[0]=0;bool zero=true;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]) zero=false;
			s[i]=s[i-1]+a[i];
		}
		if(zero){
			if(flag) printf("\n"); else flag=true;
			printf("0\n1 1\n");
			continue;
		}
		l[1]=0;m.clear();m.insert(make_pair(a[1],1));
		for(int i=2;i<=n;i++){
			auto it=m.lower_bound(a[i]);
			if(it==m.begin()) l[i]=0;
			else l[i]=(--it)->second;
			while(it=m.end(),it!=m.begin()&&(--it)->first>=a[i])
				m.erase(it);
			m.insert(make_pair(a[i],i));
		}
		r[n]=n+1;m.clear();m.insert(make_pair(a[n],n));
		for(int i=n-1;i;i--){
			auto it=m.lower_bound(a[i]);
			if(it==m.begin()) r[i]=n+1;
			else r[i]=(--it)->second;
			while(it=m.end(),it!=m.begin()&&(--it)->first>=a[i])
				m.erase(it);
			m.insert(make_pair(a[i],i));
		}
		LL ans=-1;int ansl=1,ansr=1;
		for(int i=1;i<=n;i++){
			LL t=(s[r[i]-1]-s[l[i]])*a[i];
			if(t>ans) ans=t,ansl=l[i]+1,ansr=r[i]-1;
			else if(t==ans&&r[i]-l[i]-2>ansr-ansl)
				ansl=l[i]+1,ansr=r[i]-1;
			else if(t==ans&&r[i]-l[i]-2==ansr-ansl&&l[i]+1<ansl)
				ansl=l[i]+1,ansr=r[i]-1;
		}
		if(flag) printf("\n"); else flag=true;
		printf("%lld\n%d %d\n",ans,ansl,ansr);
	}
	return 0;
}
