/* 給定Ｎ面鏡子座標和類型( 0:/ 1:\ )，光線從(0,0)向右射出，問會經過幾次的折射？
 * 題目保證同一個位置只會有一面鏡子 而且 雷射光線不會進入無限循環中 
 * 解題關鍵：二分搜尋
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=25e4;
const int MaxP=3e4;
 
struct MIRROR{ 
	int p, t;
	MIRROR(int p=0,int t=-1):p(p),t(t){}
	bool operator<(const MIRROR rhs)const{ 
		return p<rhs.p; }
};
vector<MIRROR> mx[30001];
vector<MIRROR> my[60001];
int x, y, d, p;
bool light(){
	switch(d){ // { R, D, L, U }
		case 0:
			if( my[y].empty() or x==my[y].back().p ) 
				return false;
			p=upper_bound(my[y].begin(),my[y].end(),MIRROR(x))-my[y].begin();
			d=( my[y][p].t )? 1: 3;
			x=my[y][p].p;
			return true;
 
		case 1:
			if( mx[x].empty() or y==mx[x][0].p ) 
				return false;
			p=lower_bound(mx[x].begin(),mx[x].end(),MIRROR(y))-mx[x].begin()-1;
			d=( mx[x][p].t )? 0: 2;
			y=mx[x][p].p;
			return true;
 
		case 2:
			if( my[y].empty() or x==my[y][0].p ) 
				return false;
			p=lower_bound(my[y].begin(),my[y].end(),MIRROR(x))-my[y].begin()-1;
			d=( my[y][p].t )? 3: 1;
			x=my[y][p].p;
			return true;
 
		case 3:
			if( mx[x].empty() or y==mx[x].back().p ) 
				return false;
			p=upper_bound(mx[x].begin(),mx[x].end(),MIRROR(y))-mx[x].begin();
			d=( mx[x][p].t )? 2: 0;
			y=mx[x][p].p;
			return true;
	}
	return false;
}
int main(){
	int N, t;
	scanf("%d",&N);
	for(int n=0; n<N; n++){
		scanf("%d %d %d",&x,&y,&t); y+=MaxP;
		mx[x].push_back( MIRROR(y,t) );
		my[y].push_back( MIRROR(x,t) );
	}
    // sort for binary_search
	for(x=0; x<=MaxP; x++)
		sort(mx[x].begin(),mx[x].end());
	for(y=0; y<=MaxP<<1; y++)
		sort(my[y].begin(),my[y].end());
	// init setting
    int ans=0;
	x=d=0;
	y=MaxP;
	while( light() )
		ans++;
	printf("%d",ans);
}