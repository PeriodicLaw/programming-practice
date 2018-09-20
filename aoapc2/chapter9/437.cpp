#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=;
vector<tuple<int,int,int>> a;
int f[MAXN];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int n,count=0;
	while(cin>>n&&n){
		a.clear();
		for(int i=0;i<n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a.push_back(tie(x,y,z));
			a.push_back(tie(x,z,y));
			a.push_back(tie(y,x,z));
			a.push_back(tie(y,z,x));
			a.push_back(tie(z,x,y));
			a.push_back(tie(z,y,x));
		}
		sort(a.begin(),a.end());
		f[0]=get<2>(a[0]);
		int ans=f[0];
		for(int i=1;i<6*n;i++){
			f[i]=0;
			for(int j=0;j<i;j++)
				if(get<0>(a[j])<get<0>(a[i])&&get<1>(a[j])<get<1>(a[i]))
					if(f[j]>f[i])
						f[i]=f[j];
			f[i]+=get<2>(a[i]);
			if(f[i]>ans) ans=f[i];
		}
		printf("Case %d: maximum height = %d\n",++count,ans);
	}
	return 0;
}