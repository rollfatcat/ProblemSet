/* 給定Ｎ個 Queen 和Ｍ個 Rook 擺在(Ｎ+Ｍ)的棋盤上互不衝突的方法數？
 * 解題核心：八皇后的變形版
 * 城堡只需考慮直行是否存在其他棋子不需要考慮斜角線，之後若要再擺上皇后會有影響。
 * 狀態的設定：
 * col＝城堡或皇后都需要考慮"是否"擺放其他棋子，boolean 紀錄。
 * psh、nsh＝城堡不考慮但皇后需要，處理"城堡還原"時只有還原到數量＝０才能放皇后，所以需要紀錄數量(int)
 *          一旦該斜角線存在皇后時直接將數量扣到０代表不能再放入城堡，還原時則回覆到"最大值"。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCnt=10;
bool col[MaxCnt];
int psh[MaxCnt<<1];
int nsh[MaxCnt<<1];
int ans, base;

void DFS(int Queen,int Rook,int y){
	if(y==base){ ans++; return; }
	for(int x=0;x<base;x++){
		if(Queen>0 and col[x] and psh[x+y]==base and nsh[x-y+base]==base){	
			col[x]=psh[x+y]=nsh[x-y+base]=0;
			DFS(Queen-1,Rook,y+1);
			col[x]=1, psh[x+y]=nsh[x-y+base]=base;
		}
		if(Rook>0 and col[x] and psh[x+y] and nsh[x-y+base]){	
			col[x]=0, psh[x+y]--, nsh[x-y+base]--;
			DFS(Queen,Rook-1,y+1);
			col[x]=1, psh[x+y]++, nsh[x-y+base]++;
		}
	}
}
int main(){
	int N, M;
	while(scanf("%d %d\n",&N,&M)!=EOF){
		base=N+M;
		fill(col,col+base,1);
		fill(psh,psh+(base<<1),base);
		fill(nsh,nsh+(base<<1),base);
		ans=0;
		DFS(N,M,0);
		printf("%d\n",ans);
	}
}