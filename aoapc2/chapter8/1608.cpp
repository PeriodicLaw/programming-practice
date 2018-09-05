#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
using namespace std;
const int MAXN=200100;
int n,a[MAXN],p[MAXN],q[MAXN];
void init(){
	map<int,int> s;
	for(int i=0;i<n;i++){
		auto it=s.find(a[i]);
		if(it==s.end()){
			p[i]=-1;
			s.insert(make_pair(a[i],i));
		}else{
			p[i]=it->second;
			it->second=i; 
		}
	}
	s.clear();
	for(int i=n-1;i>=0;i--){
		auto it=s.find(a[i]);
		if(it==s.end()){
			q[i]=n;
			s.insert(make_pair(a[i],i));
		}else{
			q[i]=it->second;
			it->second=i;
		}
	}
}
bool solve(int l,int r){
	if(l+1>=r) return true;
	for(int i=l,j=r-1;i<=j;i++,j--)
		if(p[i]<l&&q[i]>=r)
			return solve(l,i)&&solve(i+1,r);
		else if(p[j]<l&&q[j]>=r)
			return solve(l,j)&&solve(j+1,r);
	return false;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		init();
		printf(solve(0,n)?"non-boring\n":"boring\n");
	}
	return 0;
}
