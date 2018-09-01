#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<utility>
using namespace std;
const int MAXN=10,INF=100;
typedef set<pair<int,int>> lattice;
void move(lattice &lat){
	lattice lat1;
	int minx=INF,miny=INF;
	for(auto p:lat) minx=min(minx,p.first),miny=min(miny,p.second);
	for(auto p:lat) lat1.insert(make_pair(p.first-minx,p.second-miny));
	lat=lat1;
}
lattice rotate(const lattice &lat){
	lattice lat2;
	for(auto p:lat) lat2.insert(make_pair(p.second,-p.first));
	move(lat2);
	return lat2;
}
lattice flip(const lattice &lat){
	lattice lat2;
	for(auto p:lat) lat2.insert(make_pair(p.first,-p.second));
	move(lat2);
	return lat2;
}
set<lattice> lattices;
bool repeated(const lattice &lat){
	if(lattices.find(lat)!=lattices.end()) return true;
	lattice lat1=lat;
	lattices.insert(lat1);
	lat1=rotate(lat1);lattices.insert(lat1);
	lat1=rotate(lat1);lattices.insert(lat1);
	lat1=rotate(lat1);lattices.insert(lat1);
	lat1=flip(lat1);
	lattices.insert(lat1);
	lat1=rotate(lat1);lattices.insert(lat1);
	lat1=rotate(lat1);lattices.insert(lat1);
	lat1=rotate(lat1);lattices.insert(lat1);
	return false;
}
const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int n,w,h,ans;
bool inmap(const lattice &lat){
	for(auto p:lat) if(p.first>=w||p.second>=h) return false;
	return true;
}
bool caninmap(lattice lat){
	lattice lat1=lat;
	if(inmap(lat)) return true;
	lat1=rotate(lat1);if(inmap(lat)) return true;
	lat1=rotate(lat1);if(inmap(lat)) return true;
	lat1=rotate(lat1);if(inmap(lat)) return true;
	lat1=flip(lat1);
	if(inmap(lat1)) return true;
	lat1=rotate(lat1);if(inmap(lat1)) return true;
	lat1=rotate(lat1);if(inmap(lat1)) return true;
	lat1=rotate(lat1);if(inmap(lat1)) return true;
	return false;
}
lattice cur[MAXN];
void dfs(int d){
	if(d==n-1){
		++ans;
		return;
	}
	for(auto p:cur[d])
		for(int i=0;i<4;i++){
			auto p1=make_pair(p.first+dx[i],p.second+dy[i]);
			if(cur[d].find(p1)==cur[d].end()){
				cur[d+1]=cur[d];cur[d+1].insert(p1);move(cur[d+1]);
				if(caninmap(cur[d+1])&&!repeated(cur[d+1]))
					dfs(d+1);
			}
		}
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    while(scanf("%d%d%d",&n,&w,&h)==3){
    	lattices.clear();
    	cur[0].clear();
    	cur[0].insert(make_pair(0,0));
    	ans=0;
    	dfs(0);
    	printf("%d\n",ans);
	}
	return 0;
}
