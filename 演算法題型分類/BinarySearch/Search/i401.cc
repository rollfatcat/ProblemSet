/* 給定Ｎ面鏡子座標和類型( 0:/ 1:\ )，光線從(0,0)向右射出，問會經過幾次的折射？
 * 題目保證同一個位置只會有一面鏡子 而且 雷射光線不會進入無限循環中 
 * 解題關鍵：二分搜尋
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=25e4;
const int MaxX=3e4;
const int MaxY=6e4;

struct NODE{ 
	int p, t; 
	NODE(int p=0,int t=0):p(p),t(t){}
} ret;
vector<NODE> mx[MaxX+1];
vector<NODE> my[MaxY+1];

bool comp(NODE lhs,NODE rhs){ return lhs.p<rhs.p; }
// pass by reference : avoid to copy one
NODE upper_bound(int v,vector<NODE>& pool){ // find the mirror, who's position > v
	if( pool.empty() or pool.back().p<=v ) 
		return NODE(0,-1);
	int L=0;
	int R=pool.size()-1;
	int ans=-1;
	while( L<=R ){
		int M=L+R>>1;
		if( v<pool[M].p ){
			ans=M;
			R=M-1;
		}else
			L=M+1;
	}
	return (ans==-1)? NODE(0,-1): pool[ans];
}
NODE lower_bound(int v,vector<NODE>& pool){ // find the mirror, who's position < v
	if( pool.empty() or v<=pool[0].p ) 
		return NODE(0,-1);
	int L=0;
	int R=pool.size()-1;
	int ans=-1;
	while( L<=R ){
		int M=L+R>>1;
		if( pool[M].p<v ){
			ans=M;
			L=M+1;
		}else
			R=M-1;
	}
	return (ans==-1)? NODE(0,-1): pool[ans];
}


int main(){
	int N, x, y, t;
	
	cin>>N;
	while( N-->0 ){
		cin>>x>>y>>t; 
		y+=30000; // offset ->  0 <= y <=6e4
		mx[x].push_back( NODE(y,t) );
		my[y].push_back( NODE(x,t) );
	}
	for(int x=1; x<=MaxX; x++)
		sort( mx[x].begin(), mx[x].end(), comp );
	for(int y=0; y<=MaxY; y++)
		sort( my[y].begin(), my[y].end(), comp );
	
	// init status
	int S_x=0;
	int S_y=30000;
	int S_d=0; // { R=0, D=1, L=2, U=3 }
	for(int cnt=0; true; cnt+=1){
		switch( S_d ){
			case 0:
				ret=upper_bound(S_x, my[S_y]);	
				if( ret.t==-1 ){ // 找不到時回傳的鏡子類型為 -1
					cout<<cnt; return 0; }
				S_x= ret.p;
				S_d= ret.t==0? 3: 1;
				break;
			case 1:
				ret=lower_bound(S_y, mx[S_x]);	
				if( ret.t==-1 ){ // 找不到時回傳的鏡子類型
					cout<<cnt; return 0; }
				S_y= ret.p;
				S_d= ret.t==0? 2: 0;
				break;
			case 2:
				ret=lower_bound(S_x, my[S_y]);	
				if( ret.t==-1 ){ // 找不到時回傳的鏡子類型
					cout<<cnt; return 0; }
				S_x= ret.p;
				S_d= ret.t==0? 1: 3;
				break;
			case 3:
				ret=upper_bound(S_y, mx[S_x]);	
				if( ret.t==-1 ){ // 找不到時回傳的鏡子類型
					cout<<cnt; return 0; }
				S_y= ret.p;
				S_d= ret.t==0? 0: 2;
		}
	}
}