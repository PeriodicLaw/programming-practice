#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
using namespace std;
const int MAXN=105;
int n,m,f,token[MAXN];
map<int,int> input[MAXN],output[MAXN];
inline bool check(int i){
	for(auto j:input[i])
		if(token[j.first]<j.second)
			return false;
	return true;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int count=0;
    while(scanf("%d",&n)==1&&n){
    	for(int i=1;i<=n;i++) scanf("%d",&token[i]);
    	scanf("%d",&m);
    	for(int i=0,t;i<m;i++){
    		input[i].clear();output[i].clear();
    		while(scanf("%d",&t)==1&&t)
				if(t>0) ++output[i][t];
				else ++input[i][-t];
		}
		scanf("%d",&f);
		bool live=true;
		++count;
		for(int now=0;now<f;now++){
			bool live1=false;
			for(int i=0;i<m;i++)
				if(check(i)){
					for(auto j:input[i]) token[j.first]-=j.second;
					for(auto j:output[i]) token[j.first]+=j.second;
					live1=true;
					break;
				}
			if(!live1){
				live=false;
				printf("Case %d: dead after %d transitions\nPlaces with tokens:",count,now);
				break;
			}
		}
		if(live)
			printf("Case %d: still live after %d transitions\nPlaces with tokens:",count,f);
		for(int i=1;i<=n;i++)
			if(token[i])
				printf(" %d (%d)",i,token[i]);
		printf("\n\n");
	}
	return 0;
}

