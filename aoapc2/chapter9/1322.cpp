#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int INF=10000000;
struct segnode{
	int x,y,tag;
	segnode *l,*r;
};
void init(segnode *(&t),int l,int r,int x){
	t=(segnode*)malloc(sizeof(segnode));
	t->x=l;t->y=r;t->tag=x;t->l=nullptr;t->r=nullptr;
	if(l!=r){
		init(t->l,l,(l+r)/2,x);
		init(t->r,(l+r)/2+1,r,x);
	}
}
void destroy(segnode *(&t)){
	if(t->x!=t->y){
		destroy(t->l);
		destroy(t->r);
	}
	free(t);
}
int query(segnode *t,int a){
//return t[a]
	if(t->tag!=-1||t->x==t->y) return t->tag;
	if(a<=(t->x+t->y)/2) return query(t->l,a);
	else return query(t->r,a);
}
void update1(segnode *t,int x){
	if(t->tag>=0){
		if(x<t->tag) t->tag=x;
		return;
	}
	int m=(t->x+t->y)/2,xm=query(t,m);
	if(xm>x){
		update1(t->l,x);
		t->r->tag=x;
	}else{
		update1(t->r,x);
	}
}
void update(segnode *t,int l,int r,int x){
//t[i]=min{t[i],x},l<=i<=r
	if(t->x==l&&t->y==r){
		update1(t,x);
		return;
	}
	if(t->tag>=0){
		t->l->tag=t->tag;
		t->r->tag=t->tag;
		t->tag=-1;
	}
	int m=(t->x+t->y)/2;
	if(l<=m)
		if(r<=m)
			update(t->l,l,r,x);
		else{
			update(t->l,l,m,x);
			update(t->r,m+1,r,x);
		}
	else
		update(t->r,l,r,x);
	return;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	segnode *root;
	int z;scanf("%d",&z);
	bool flag=false;
	while(z--){
		int n,m;scanf("%d%d",&n,&m);
		init(root,1,n,INF);
		update(root,1,1,0);
		for(int i=0;i<m;i++){
			int a,b;scanf("%d%d",&a,&b);
			int x=query(root,a);
			if(x<INF)
				update(root,a,b,x+1);
		}
		int ans=query(root,n);
		if(flag) printf("\n"); else flag=true;
		printf("%d\n",ans);
		destroy(root);
	}
	return 0;
}
