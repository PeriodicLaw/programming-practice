#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm> 
using namespace std;
typedef long long LL;
const int MAXN=5010;
int a[MAXN];
vector<int> r[MAXN],l[MAXN];
bool cmp(int x,int y){
	return a[x]<a[y];
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(int i=0;i<n;i++){
			l[i].clear();
			for(int j=i-1;j>=0;j--)
				if(a[j]<a[i]){
					l[i]=l[j];
					l[i].insert(l[i].end(),j);
					break;
				}
		}
		for(int i=n-1;i>=0;i--){
			r[i].clear();
			for(int j=i+1;j<n;j++)
				if(a[j]>a[i]){
					r[i]=r[j];
					r[i].insert(r[i].begin(),j);
					break;
				}
		}
		for(int i=0;i<n-1;i++)
			for(int j=i+1;j<n;j++)
				if(a[i]<a[j]){
					auto p=lower_bound(r[i].begin(),r[i].end(),j,cmp);
					if(p!=r[i].end()&&a[*p]==a[j]) ++p;
					if(p==r[i].end()) continue;
					auto q=lower_bound(l[j].begin(),l[j].end(),i,cmp);
					if(q!=l[j].begin()) --q; else continue;
					if(*p<*q){
						printf("YES\n");
						goto label;
					}
				}
		for(int i=0;i<n;i++){
			l[i].clear();
			for(int j=i-1;j>=0;j--)
				if(a[j]>a[i]){
					l[i]=l[j];
					l[i].insert(l[i].begin(),j);
					break;
				}
		}
		for(int i=n-1;i>=0;i--){
			r[i].clear();
			for(int j=i+1;j<n;j++)
				if(a[j]<a[i]){
					r[i]=r[j];
					r[i].insert(r[i].end(),j);
					break;
				}
		}
		for(int i=0;i<n-1;i++)
			for(int j=i+1;j<n;j++)
				if(a[i]>a[j]){
					auto p=lower_bound(r[i].begin(),r[i].end(),j,cmp);
					if(p!=r[i].begin()) --p; else continue;
					auto q=lower_bound(l[j].begin(),l[j].end(),i,cmp);
					if(q!=l[j].end()&&a[*q]==a[i]) ++q;
					if(q==l[j].end()) continue;
					if(*p<*q){
						printf("YES\n");
						goto label;
					}
				}
		printf("NO\n");
		label:;
	}
	return 0;
}
