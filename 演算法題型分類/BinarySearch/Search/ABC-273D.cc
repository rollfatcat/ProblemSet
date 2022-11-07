/* 給定
 *
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=2e5;
const int MaxQ=2e5;
const int MaxR=1e9;
struct NODE{
	int r, c;
} now, node[MaxN];

vector<int> ur; // 離散化 - 儲存出現過的ｒ座標
vector<int> uc; // 離散化 - 儲存出現過的ｃ座標
vector<int> nr[MaxN]; // 對應相同ｒ座標時ｃ座標值由小到大，便於二分搜尋
vector<int> nc[MaxN]; // 對應相同ｃ座標時ｒ座標值由小到大，便於二分搜尋

int InSet(int v,vector<int>& pool,int p=0){
	p=lower_bound(pool.begin(),pool.end(),v)-pool.begin();
	return (p<pool.size() and v==pool[p])? p: -1;
}
int main(){
	int R, C, N, Q;
	int r, c, v;
	char chd;
	// input - wall
	cin>>R>>C>>now.r>>now.c;
	cin>>N;
	for(int n=0; n<N; n++)
		cin>>node[n].r>>node[n].c;
	//
	sort(node,node+N,[](NODE lhs,NODE rhs){ return (lhs.r!=rhs.r)? lhs.r<rhs.r: lhs.c<rhs.c; });
	   ur.push_back( node[0].r );
	nr[0].push_back( node[0].c );
	for(int n=1; n<N; n++){
		if( ur.back()!=node[n].r )
			ur.push_back( node[n].r );
		nr[ ur.size()-1 ].push_back( node[n].c );
	}
	// 
	sort(node,node+N,[](NODE lhs,NODE rhs){ return (lhs.c!=rhs.c)? lhs.c<rhs.c: lhs.r<rhs.r; });
	   uc.push_back( node[0].c );
	nc[0].push_back( node[0].r );
	for(int n=1; n<N; n++){
		if( uc.back()!=node[n].c )
			uc.push_back( node[n].c );
		nc[ uc.size()-1 ].push_back( node[n].r );
	}
	// online - process
	cin>>Q;
	while( Q-->0 ){
		cin>>chd>>v;
		switch(chd){
			case 'L':
				r=InSet(now.r,ur);
				if( r==-1 or (c=upper_bound(nr[r].begin(),nr[r].end(),now.c)-nr[r].begin())==0 ){
					now.c=max(1,now.c-v);
				}else{
					now.c=max(nr[r][c-1]+1,now.c-v);
				}
				break;
			case 'R':
				r=InSet(now.r,ur);
				if( r==-1 or (c=upper_bound(nr[r].begin(),nr[r].end(),now.c)-nr[r].begin())==nr[r].size() ){
					now.c=min(C,now.c+v);
				}else{
					now.c=min(nr[r][c]-1,now.c+v);
				}
				break;
			case 'U':
				c=InSet(now.c,uc);
				if( c==-1 or (r=upper_bound(nc[c].begin(),nc[c].end(),now.r)-nc[c].begin())==0 ){
					now.r=max(1,now.r-v);
				}else{
					now.r=max(nc[c][r-1]+1,now.r-v);
				}
				break;
			case 'D':
				c=InSet(now.c,uc);
				if( c==-1 or (r=upper_bound(nc[c].begin(),nc[c].end(),now.r)-nc[c].begin())==nc[c].size() ){
					now.r=min(R,now.r+v);
				}else{
					now.r=min(nc[c][r]-1,now.r+v);
				}
				break;
		}
		cout<<now.r<<' '<<now.c<<'\n';
	}
}