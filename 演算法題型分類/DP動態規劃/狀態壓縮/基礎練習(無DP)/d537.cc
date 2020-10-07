/* 給定Ｎ×Ｎ地圖、ＹＢＲ三原色的起始座標，輸出指定顏色在「擴散」過程中最多的格子數？
 * 擴散方式：每秒向周圍８個方向往外一格染色，同一格受到不同顏色渲染時顏色會疊加(疊加原理採顏色)。
 * 解題關鍵：狀態壓縮(混色＝OR位元運算)
 * 加速技巧：每當某格「顏色改變」時，舊顏色的數量-1，新顏色數量+1，避開每次都要掃描整張圖。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=100;
char color[1<<7]={};
int board[MaxN][MaxN];
int cnt[8];
int st_x[3];
int st_y[3];
/* 經歷模擬ｔ秒時三原色擴散的結果 */
inline void CircleColor(int N,int t){
	/* 第ｔ秒擴散時最外圍的偏移座標 */
	vector<int> dx;
	vector<int> dy;
	for(int i=-t; i<t; i++){
		dx.push_back(-t); dy.push_back( i);
		dx.push_back( t); dy.push_back(-i);
		dx.push_back( i); dy.push_back( t);
		dx.push_back(-i); dy.push_back(-t);
	}
	for(int color_i=0;color_i<3;color_i++)
		for(int i=0;i<dx.size();i++){
			int x=st_x[ color_i ]+dx[i];
			int y=st_y[ color_i ]+dy[i];
			if(x<0 or x>=N or y<0 or y>=N) continue;
			cnt[ board[x][y] ]--;
			board[x][y]|= (1<<color_i);
			cnt[ board[x][y] ]++;
		}
}
int main(){
  /* 位元描述三原色，顏色疊加＝OR位元運算
   * Y: 001  B: 010  R: 100
   * G: 011  O: 101  P: 110
   * D: 111  W: 000
   */
	color['Y']=1; color['B']=2; color['R']=4; 
	color['G']=3; color['O']=5; color['P']=6;
	color['D']=7;
	
	char target_c;
	int N, x, y;
	
	while(scanf("%d\n",&N)!=EOF){
		/* 初始化每一格，白(無)色有Ｎ×Ｎ個，其他顏色個數都是０ */
    for(int i=0;i<N;i++)
			fill(board[i],board[i]+N,0);
		cnt[0]=N*N;
		cnt[1]=cnt[2]=cnt[3]=cnt[4]=cnt[5]=cnt[6]=cnt[7]=0;
		for(int i=0;i<3;i++){
			scanf("%c %d %d\n",&target_c,&x,&y);
			target_c=color[target_c];
			st_x[__lg(target_c)]=x; 
      st_y[__lg(target_c)]=y;
			cnt[ board[x][y] ]--;
			board[x][y]|=target_c;
			cnt[ board[x][y] ]++;
		}
		scanf("%c\n",&target_c);
		target_c=color[target_c];
		
		int ans_cnt=0;
    /* 從最角落的座標開始染色，最多Ｎ秒整張地圖都會染上該顏色 */
		for(int nowT=1;nowT<N;nowT++){
			CircleColor(N,nowT);
			ans_cnt=max(ans_cnt,cnt[target_c]);
		}
		printf("%d\n",ans_cnt);
	}
}