#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<utility>
using namespace std;
const int MAXS=6,MAXN=1<<MAXS;
int s,weight[MAXS];
double r,sum[MAXN];
vector<pair<double,double>> tree[MAXN];
void dfs(int set){
	if(!tree[set].empty()) return;
	bool single=true;
	for(int left=1;left<set;left++)
		if((left|set)==set){
			single=false;
			int right=set-left;
			dfs(left);
			dfs(right);
			double d1=sum[right]/sum[set],d2=sum[left]/sum[set];
			for(auto i:tree[left])
				for(auto j:tree[right])
					tree[set].push_back(make_pair(max(i.first+d1,j.first-d2),max(i.second-d1,j.second+d2)));
		}
	if(single) tree[set].push_back(make_pair(0.0,0.0));
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int num;scanf("%d",&num);
    while(num--){
    	scanf("%lf%d",&r,&s);
    	for(int i=0;i<s;i++) scanf("%d",&weight[i]);
    	for(int i=0;i<1<<s;i++){
    		tree[i].clear();
    		sum[i]=0;
    		for(int j=0;j<s;j++)
    			if((1<<j|i)==i)
    				sum[i]+=weight[j];
		}
    	dfs((1<<s)-1);
    	double ans=-1;
    	for(auto p:tree[(1<<s)-1])
    		if(p.first+p.second<r)
    			ans=max(ans,p.first+p.second);
    	if(ans==-1)
    		printf("-1\n");
    	else
    		printf("%.12lf\n",ans);
	}
	return 0;
}

