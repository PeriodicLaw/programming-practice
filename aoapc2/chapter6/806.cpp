#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=100;
int n;
int image[MAXN][MAXN],s[MAXN][MAXN];
vector<int> paths;
void make(int lx,int ly,int rx,int ry,int path,int power){
	int countblack=s[rx][ry]+s[lx][ly]-s[lx][ry]-s[rx][ly];
	if(countblack==0) return;
	if(countblack==(rx-lx)*(ry-ly)){
		paths.push_back(path);
		return;
	}
	int mx=(lx+rx)/2,my=(ly+ry)/2;
	make(lx,ly,mx,my,path+power,power*5);
	make(lx,my,mx,ry,path+power*2,power*5);
	make(mx,ly,rx,my,path+power*3,power*5);
	make(mx,my,rx,ry,path+power*4,power*5);
}
void imagetopaths(){
	char c;
	for(int i=1;i<=n;i++){
		scanf(" ");
		for(int j=1;j<=n;j++)
			image[i][j]=getchar()=='1';
	}
	memset(s,0,sizeof(s));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+image[i][j];
	paths.clear();
	make(0,0,n,n,0,1);
	sort(paths.begin(),paths.end());
	for(int i=0;i<paths.size();i++){
		if(i%12==0) printf("\n"); else printf(" ");
		printf("%d",paths[i]);
	}
	printf("\nTotal number of black nodes = %d\n",paths.size());
	return;
}
void pathstoimage(){
	memset(image,0,sizeof(image));
	int m;
	while(scanf("%d",&m)==1&&m!=-1){
		int lx=0,ly=0,rx=n,ry=n;
		while(m){
			int mx=(lx+rx)/2,my=(ly+ry)/2;
			switch(m%5){
				case 1:rx=mx,ry=my;break;
				case 2:ly=my,rx=mx;break;
				case 3:lx=mx,ry=my;break;
				case 4:lx=mx,ly=my;break;
			}
			m/=5;
		}
		for(int i=lx+1;i<=rx;i++)
			for(int j=ly+1;j<=ry;j++)
				image[i][j]=1;
	}
	for(int i=1;i<=n;i++){
		printf("\n");
		for(int j=1;j<=n;j++)
			printf(image[i][j]?"*":".");
	}
	printf("\n");
	return;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int count=0;
    while(scanf("%d",&n)==1&&n){
    	if(count) printf("\n");
    	printf("Image %d",++count);
    	if(n>0)
    		imagetopaths();
    	else
    		n=-n,pathstoimage();
	}
	return 0;
}
