/* 給定ＲxＣ的地圖每一格都有數字代表顏色，對指定位置上色Ｚ後，輸出內容？
 * 染色 = 周遭４格與他相同的顏色也會變成Ｚ，直到「連通區塊」內的顏色都轉變成Ｚ
 * 解題核心： DFS 探索枚舉方格迷宮
 * 實作盲點： 遞迴時受限於堆疊上限，該題必須用 stack 自己實作
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxR=5e2;
const int MaxC=5e2;
const int MaxV=99;
int hgt[MaxR][MaxC];

struct NODE{
	int r, c;
	NODE(int r=0,int c=0):r(r),c(c){}
} ;
int main(){
	int R, C, Sr, Sc, v, Z, r, c;
	
	cin>>R>>C>>Sr>>Sc>>Z;
	for(int r=0; r<R; r++)
		for(int c=0; c<C; c++)
			cin>>hgt[r][c];
	// depth search first by stack
	vector<NODE> stk;
	v=hgt[Sr-1][Sc-1];
	if( v!=Z ){
		hgt[Sr-1][Sc-1]=Z;
		stk.push_back( NODE(Sr-1,Sc-1) );
	}
	while( !stk.empty() ){
		r=stk.back().r;
		c=stk.back().c;
		stk.pop_back();
		if(0<r and hgt[r-1][c]==v){
			hgt[r-1][c]=Z;
			stk.push_back(NODE(r-1,c));
		}
		if(0<c and hgt[r][c-1]==v){ 
			hgt[r][c-1]=Z;
			stk.push_back(NODE(r,c-1));
		}
		if(r+1<R and hgt[r+1][c]==v){
			hgt[r+1][c]=Z;
			stk.push_back(NODE(r+1,c));
		}
		if(c+1<C and hgt[r][c+1]==v){ 
			hgt[r][c+1]=Z;
			stk.push_back(NODE(r,c+1));
		}
	}
	// output
	for(int r=0; r<R; r++, cout<<"\n")
		for(int c=0; c<C; c++)
			cout<<hgt[r][c]<<" ";
}