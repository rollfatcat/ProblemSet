/* 給定初始時３堆石頭的數量，依照規則問先手玩家的結果是贏還是輸？
 * 規則：玩家可以從３堆石頭至少任選一堆取最少一顆石頭。
 * 解題關鍵：Nim( 動態規劃 )
 * 初始狀態：(０,０,０) ＝當玩家面臨該狀態時必輸
 * 所有狀態：必輸/存在贏的局面(０/１)
 * 狀態轉移：枚舉所有可以透過"移除規則"形成的子狀態，若子狀態"皆"為贏代表目前狀態必輸
 * 		   移除規則形成的子狀態為７種可能的變化方向(並枚舉移除數量)
 * Top-Down  | 700ms 
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=101;
int dpv[MaxN][MaxN][MaxN];
bool Recursive(int xS,int yS,int zS){
  /* Branch-Cut：排序，(3,1,2),(2,3,1)都能視為(1,2,3) */
	int nowS[3]={xS,yS,zS};
	sort(nowS,nowS+3);
	/* 若這個狀態還沒幾算過則呼叫遞迴，將該狀態改為輸(預設值)
	 * 若子狀態存在一個輸代表目前狀態存在贏的機會。 
	 */
  if(dpv[nowS[0]][nowS[1]][nowS[2]]==-1){
		dpv[nowS[0]][nowS[1]][nowS[2]]=0;
		for(int i=1;i<=nowS[0];i++)
			dpv[nowS[0]][nowS[1]][nowS[2]]|= 
				!Recursive(nowS[0]-i,nowS[1],  nowS[2]  )| 
				!Recursive(nowS[0]-i,nowS[1]-i,nowS[2]  )| 
				!Recursive(nowS[0]-i,nowS[1],  nowS[2]-i)| 
				!Recursive(nowS[0]-i,nowS[1]-i,nowS[2]-i);
		for(int i=1;i<=nowS[1];i++)
			dpv[nowS[0]][nowS[1]][nowS[2]]|= 
				!Recursive(nowS[0],nowS[1]-i,nowS[2]  )| 
				!Recursive(nowS[0],nowS[1]-i,nowS[2]-i);
		for(int i=1;i<=nowS[2];i++)
			dpv[nowS[0]][nowS[1]][nowS[2]]|= 
				!Recursive(nowS[0],nowS[1],nowS[2]-i);
	}
	return dpv[nowS[0]][nowS[1]][nowS[2]];
}
int main(){
	memset(dpv,-1,sizeof(dpv));
	dpv[0][0][0]=0;
	
	int xS, yS, zS;
	while(scanf("%d",&xS)!=EOF and xS>0){
		scanf(" %d %d\n",&yS,&zS);
		puts( Recursive(xS,yS,zS)? "w": "l" );
	}
}
