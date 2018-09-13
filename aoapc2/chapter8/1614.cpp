#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN=100100;
pair<int,int> a[MAXN];
int b[MAXN];
bool cmp(const pair<int,int> &a,const pair<int,int> &b){
	return a.first>b.first;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i].first);
			a[i].second=i;
		}
		sort(a,a+n,cmp);
		int s=0;
		for(int i=0;i<n;i++){
			b[a[i].second]=(s>0)?-1:1;
			s+=b[a[i].second]*a[i].first;
		}
		if(s==0){
			printf("Yes\n");
			for(int i=0;i<n;i++){
				if(i) printf(" ");
				printf("%d",b[i]);
			}
			printf("\n");
		}else
			printf("No\n");
	}
	return 0;
}

