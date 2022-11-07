/* 題目保證答案會≦ 1e15
 * 將棋盤轉45度後拆成黑白兩個獨立區域
 * 分析：針對黑/白區域枚舉暴力枚舉，深度(MAX_Board_Len=30)
 * 每層的平均選項是15 white=(1,1,...,29,29) => 暴力法無法通過
 * 標準解：動態規劃
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 31

short Board_Len, Bishop;
short whiteLen[MAXN]={0,1,1,3,3,5,5,7,7,9,9,11,11,13,13,15,15,17,17,19,19,21,21,23,23,25,25,27,27,29,29};
short blackLen[MAXN]={0,0,2,2,4,4,6,6,8,8,10,10,12,12,14,14,16,16,18,18,20,20,22,22,24,24,26,26,28,28,30};
long whiteCnt[MAXN][MAXN]={};
long blackCnt[MAXN][MAXN]={};

void PutBishop_DP(){
  // 初始化, 當要擺上去的chessNum=0, 方法數=1
  for(int len=0;len<=30;len++)
    whiteCnt[len][0]=1;
  // DP：當邊長len擺上chessNum個城堡的方法數
  for(int len=1;len<=30;len++)
    for(int num=1;num<=whiteLen[len];num++)
      whiteCnt[len][num]=whiteCnt[len-1][num]+(whiteLen[len]-num+1)*whiteCnt[len-1][num-1];
  // 同理
  for(int len=0;len<=30;len++)
    blackCnt[len][0]=1;
  for(int len=1;len<=30;len++)
    for(int num=1;num<=blackLen[len];num++)
      blackCnt[len][num]=blackCnt[len-1][num]+(blackLen[len]-num+1)*blackCnt[len-1][num-1];
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  PutBishop_DP();
  while(cin>>Board_Len>>Bishop and Board_Len){
    short max_Bishop=(Board_Len<<1)-1;
    long cnt=0;
    if(Bishop<=max_Bishop)
      for(short i=0;i<=Bishop;i++){ //判斷存取範圍合法, 不合法時方法數=0
        long whiteNum=(i<=Board_Len)? whiteCnt[Board_Len][i]: 0;
        long blackNum=(Bishop-i<=Board_Len)? blackCnt[Board_Len][Bishop-i]: 0;
        cnt+=whiteNum*blackNum;
      }
    cout<<cnt<<'\n';
  }
}
