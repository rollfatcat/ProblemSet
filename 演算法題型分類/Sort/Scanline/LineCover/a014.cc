/* 給定夾子長度Ｙ和Ｎ隻娃娃的起終點，輸出能夾到最多娃娃的個數和所有位置的數量？
 * 夾子夾到某個娃娃的定義：娃娃的起點和終點都落在夾子的左右端點內(相等也算)
 * 解題關鍵：掃描線，將一個娃娃視為起點和終點(左端點一離開該娃娃起點時-1，右端點碰到該娃娃終點時+1)
 * 問題點：終止條件＝紀錄最後一個終點的位置，該位置之後娃娃的數量只減不增。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=3e4;
const int MaxY=3e4;
const int MaxX=1e5;
/* 夾子 */
int add[MaxX+MaxY+1];

int main(){
  int N, Y, A, B;
  while(scanf("%d %d\n",&N,&Y)!=EOF){
  	memset(add,0,sizeof(add));
  	/* 紀錄最後一個終點的位置，該位置之後娃娃的數量只會減少(作為停止條件) */
    int maxB=0;
  	while(N-->0){
  		scanf("%d %d\n",&A,&B);
  		/* 該娃娃的長度超過夾子長度＝無論如何都無法夾起 */
      if(B-A>Y) continue;
  		/* 掃描線(夾子右端點)經過Ｂ點，能夠夾的娃娃數量
       * 掃描線(夾子左端點)經過Ａ點＝掃描線(夾子右端點)經過(Ａ+Ｙ+１)，需要扣除掉起點是Ａ的娃娃數量*/
      add[B]++;
  		add[A+Y+1]--;
  		maxB=max(maxB,B);
  	}
 
  	int now_cnt=0;
  	int ans_cnt=0;
  	int ans_num=0;
  	int scanline=1;
    /* 掃描線小於等於夾子長度都屬於當夾子在１時可以抓到的娃娃數 */
  	while(scanline<=Y)
  		now_cnt+=add[scanline++];
  	/* 枚舉夾子的位置從 左端點在１(右端點在Ｙ+１)直到右端點碰到最後一個終點 */
    while(scanline<=maxB){
  		now_cnt+=add[scanline++];
  		if(ans_cnt<now_cnt)
  			ans_cnt=now_cnt,
  			ans_num=0;
  		if(ans_cnt==now_cnt)
  			ans_num++;
  	}
    /* 因為題目要求輸出能夠夾到最多娃娃的所有位置個數，
     * 所以從最後一個終點開始往後算且此時的娃娃數量＝最多的娃娃數時則繼續需要繼續移動夾子。
     */
  	if(ans_cnt==now_cnt)
  		while(add[scanline++]==0)
  			ans_num++;
  	printf("%d %d\n",ans_num,ans_cnt);
  }
}