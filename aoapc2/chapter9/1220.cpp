#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<map>
using namespace std;
typedef long long LL;
const int MAXN=210;
int f[MAXN][2];
bool g[MAXN][2];
map<string,int> names;
vector<int> child[MAXN];
void dp(int n){
	f[n][0]=0;f[n][1]=1;
	g[n][0]=g[n][1]=true;
	for(auto i:child[n]){
		dp(i);
		f[n][1]+=f[i][0];
		g[n][1]&=g[i][0];
		if(f[i][0]==f[i][1])
			f[n][0]+=f[i][0],g[n][0]=false;
		else if(f[i][0]>f[i][1])
			f[n][0]+=f[i][0],g[n][0]&=g[i][0];
		else
			f[n][0]+=f[i][1],g[n][0]&=g[i][1];
	}
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int n;
	while(cin>>n&&n){
		names.clear();
		for(int i=0;i<n;i++) child[i].clear();
		string s1,s2;
		cin>>s1;names[s1]=0;
		int m=1;
		for(int i=1;i<n;i++){
			cin>>s1>>s2;
			if(names.find(s1)==names.end()) names[s1]=m++;
			if(names.find(s2)==names.end()) names[s2]=m++;
			child[names[s2]].push_back(names[s1]);
		}
		//for(int i=0;i<n;i++) printf("%d\n",t[i]);
		dp(0);
		if(f[0][0]==f[0][1])
			printf("%d No\n",f[0][0]);
		else if(f[0][0]>f[0][1])
			printf("%d %s\n",f[0][0],g[0][0]?"Yes":"No");
		else
			printf("%d %s\n",f[0][1],g[0][1]?"Yes":"No");
	}
	return 0;
}

