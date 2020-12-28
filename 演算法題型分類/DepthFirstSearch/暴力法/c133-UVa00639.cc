/* 給定Ｎ×Ｎ棋盤(最大４×４)最多能放上多少個不會相互攻擊的城堡？
 * 注意：城堡的攻擊會被障礙物阻斷( 兩座城堡間隔著一格障礙物時就不會相互攻擊 )
 * 解題關鍵：暴力法遞迴
 * 遞迴枚舉((Ｘ,Ｙ)小到大)每個格子若有選擇時則 遞迴放不放城堡，否則只能選擇不放
 * 放城堡時往十字架的方向延伸將"可以放"城堡的格子都設定為這個城堡的編號代表"不可放"
 * 還原時只能把設定過的格子做還原，其他的格子狀態不能改動。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=4;
char ss[MaxN+4];
int  use[MaxN][MaxN]; // 狀態：-2＝牆壁，-1＝空地，０＝放置的城堡編號(還原用)
int N, ans;

void Recursive(int x,int y,int cnt){
	/* Stop */
	if(x==N){  ans=max(ans,cnt); return; }
	/* To Next */
	/* 檢查能不能放：放城堡 */
	if(use[x][y]==-1){ 
		use[x][y]=cnt;
		/* 把攻擊範圍內(從目前位置延伸出去直到牆壁或是邊界)的格子設為該城堡的編號代表不能放置 */
		bool setZero[4][4]={};
		for(int U=x-1; U>=0 and use[U][y]!=-2;U--) if(use[U][y]==-1) use[U][y]=cnt;
		for(int D=x+1; D< N and use[D][y]!=-2;D++) if(use[D][y]==-1) use[D][y]=cnt;
		for(int L=y-1; L>=0 and use[x][L]!=-2;L--) if(use[x][L]==-1) use[x][L]=cnt;
		for(int R=y+1; R< N and use[x][R]!=-2;R++) if(use[x][R]==-1) use[x][R]=cnt;
		(y==N-1)? Recursive(x+1,0,cnt+1):Recursive(x,y+1,cnt+1);
		/* 還原：只能將當初設定過做還原 */
		for(int U=x-1; U>=0 and use[U][y]!=-2;U--) if(use[U][y]==cnt) use[U][y]=-1;
		for(int D=x+1; D< N and use[D][y]!=-2;D++) if(use[D][y]==cnt) use[D][y]=-1;
		for(int L=y-1; L>=0 and use[x][L]!=-2;L--) if(use[x][L]==cnt) use[x][L]=-1;
		for(int R=y+1; R< N and use[x][R]!=-2;R++) if(use[x][R]==cnt) use[x][R]=-1;
		use[x][y]=-1;
	}
	/* 不放城堡 */
	(y==N-1)? Recursive(x+1,0,cnt):Recursive(x,y+1,cnt);
}
int main(){
	while(scanf("%d\n",&N)!=EOF and N>0){
		for(int i=0;i<N;i++){
			scanf("%s\n",ss);
			for(int j=0;j<N;j++)
				use[i][j]= (ss[j]=='X')? -2:-1;
		}
		ans=0;
		Recursive(0,0,0);
		printf("%d\n",ans);
	}
}

/*
輸入：
4
....
....
....
X.X.
輸出：
4
*/