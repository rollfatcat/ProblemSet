/* 將棋盤轉45度後拆成黑白兩個獨立區域
 * 分析：針對黑/白區域枚舉暴力枚舉，深度(MAX_Board_Len=8)
 * 每層的平均選項是5 white=(1,1,3,3,5,5,7,7), black=(2,2,4,4,6,6,8)
 * 5^8 = 390625 = 3e5 => safe
 */

#include<bits/stdc++.h>
using namespace std;
#define MAXN 9
int Board_Len, Bishop;
vector<short> white;
vector<short> black;
// Slash_pick[a] 紀錄 x+y=a 這條斜線上有多少的『選項』
// 選項＝ x-y=b 這條斜線構成，紀錄b的值
vector<short> Slash_pick[MAXN<<1];
// 維護 x-y=b 這條斜線上有沒有主教存在
bool pslash[MAXN<<1]={};
bool *PS=&pslash[MAXN];

int whiteCnt[MAXN][MAXN]={};
int blackCnt[MAXN][MAXN]={};

/* 枚舉 x+y=a 的情況，當 x+y=a 時選擇 x-y=b 後遞迴向下選
 * white : a=(0,2,...,2*Board_Len-2)
 * black : a=(1,3,...,2*Board_Len-1)
 */
void PutBishop(int idxS,int Bishop,vector<short> &Slash_memo,int*cnt){
  if(idxS==Slash_memo.size()){ cnt[Bishop]++; return; }
  if(Bishop>Board_Len) return;
  PutBishop(idxS+1,Bishop,Slash_memo,cnt);
  short nowS=Slash_memo[idxS];
  for(short i=0;i<Slash_pick[nowS].size();i++)
    if(!PS[ Slash_pick[nowS][i] ])
      PS[ Slash_pick[nowS][i] ]=1,
      PutBishop(idxS+1,Bishop+1,Slash_memo,cnt),
      PS[ Slash_pick[nowS][i] ]=0;
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  //
  for(Board_Len=1;Board_Len<=8;Board_Len++){
    for(short r=0;r<Board_Len;r++)
      for(short c=0;c<Board_Len;c++)
        Slash_pick[r+c].push_back(r-c);
    for(int i=0;i<(Board_Len<<1)-1;i++)
      (i&1)? black.push_back(i): white.push_back(i);
    memset(pslash,0,sizeof(pslash));
    PutBishop(0,0,white,whiteCnt[Board_Len]);
    PutBishop(0,0,black,blackCnt[Board_Len]);

    for(short i=0;i<(Board_Len<<1)-1;i++)
      Slash_pick[i].clear();
    white.clear();
    black.clear();
  }
  //
  while(cin>>Board_Len>>Bishop and Board_Len){
    long cnt=0;
    if(Bishop<=14)
      for(short i=0;i<=Bishop;i++){
        long whiteNum=(i<=8)? whiteCnt[Board_Len][i]: 0;
        long blackNum=(Bishop-i<=7)? blackCnt[Board_Len][Bishop-i]: 0;
        cnt+=whiteNum*blackNum;
      }
    cout<<cnt<<'\n';
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