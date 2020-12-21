// 超難, 抓出動態規劃的方法
// 把棋盤的白色和黑色區塊部份拆開計算
// 白棋/黑棋盤最多各可以擺7個,超過時方法數=0 => 剪枝：#城堡>14, 方法數=0
// 狀態：當邊長len,擺放#城堡chessNum個  whiteCnt[len][chessNum]
// 將雙斜線轉45度做直線和橫線判斷即可, 但注意直線最多可以擺放的個數不等於邊長喔!!!
#include<iostream>
using namespace std;

int white[11]={0,1,1,3,3,5,5,7,7,9,9};
int black[11]={0,0,2,2,4,4,6,6,8,8,10};
long whiteCnt[11][11]={0}; // whiteCnt[len][chessNum]
long blackCnt[11][11]={0};

int main(){
  // 初始化, 當要擺上去的chessNum=0, 方法數=1
  for(int i=0;i<=10;i++)
    whiteCnt[i][0]=1;
  // DP：當邊長len擺上chessNum個城堡的方法數
  for(int i=1;i<=10;i++) //len=i
    for(int j=1;j<=white[i];j++) //chessNum=j
      whiteCnt[i][j]=whiteCnt[i-1][j]+(white[i]-j+1)*whiteCnt[i-1][j-1];
  // 同理
  for(int i=0;i<=10;i++)
    blackCnt[i][0]=1;
  for(int i=1;i<=10;i++) //len=i
    for(int j=1;j<=black[i];j++) //chessNum=j
      blackCnt[i][j]=blackCnt[i-1][j]+(black[i]-j+1)*blackCnt[i-1][j-1];

  int n, k;
  while(cin>>n>>k and n){
    long cnt=0;
    if(k<=18)
      for(int i=0;i<=k;i++){ //判斷存取範圍合法, 不合法時方法數=0
        long whiteNum=(i<=10)?whiteCnt[n][i]:0;
        long blackNum=(k-i<=10)?blackCnt[n][k-i]:0;
        cnt+=(whiteNum*blackNum);
      }
    cout<<cnt<<endl;
  }
}
/*
1
4
26
260
3368
53744
1022320
22522960
565532992
15915225216
*/