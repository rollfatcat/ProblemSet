/*
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 10

long ans_cnt;
short Qcnt, Rcnt, Bcnt;
short Board_Len, QRcnt;

short now_row[MAXN];   // 宣告成全域變數，只有當PutQR會用到
short nslash[MAXN<<1]; //+0 - +9
short pslash[MAXN<<1]; //-9 - +9
bool Col[MAXN];        //+0 - +9
bool Row[MAXN];        //+0 - +9
short *NS=&nslash[0];  // x+y：/
short *PS=&pslash[9];  // x-y：\

vector<short> white; // 紀錄有『選項』的#NS(x+y=even)
vector<short> black; // 紀錄有『選項』的#NS(x+y=odd)
vector<short> Slash_pick[MAXN<<1]; // 紀錄#NS的『選項』
long whiteCnt[11];
long blackCnt[10];

// Row從(0,N-1)中選取QRcnt個當作Queen和Rook要放的#Row
void New_QueenRookMap(int now,int st);

// 枚舉選取的Row依序放入Queen或是Rook
void PutQueenRook(int nowR,int Q,int R);

// 將棋盤轉45度後枚舉#NS，對於每個#NS枚舉#PS
// 將奇偶數分開計算(因為不會互相干擾，證明請參考a682的動態規劃解法)
void Bishop_Count();
void PutBishop(int idxS,int Bishop,vector<short> &Slash_memo,long *cnt);

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  while(cin>>Qcnt>>Rcnt>>Bcnt){

    QRcnt=Qcnt+Rcnt;
    Board_Len=QRcnt+Bcnt;

    ans_cnt=0;
    New_QueenRookMap(0,0);

    cout<<ans_cnt<<endl;
  }
}
void New_QueenRookMap(int now,int st){
  if(now==QRcnt){ // 已經「成功」選取QRcnt個#Row
    // init
    memset(Col,0,sizeof(Col));
    memset(nslash,0,sizeof(nslash));
    memset(pslash,0,sizeof(pslash));
    // 枚舉每個選取的Row依序放入Queen和Rook
    PutQueenRook(0,Qcnt,Rcnt);
    return;
  }
  for(short i=st;i<=Board_Len-QRcnt+now;i++)
    now_row[now]=i,
    New_QueenRookMap(now+1,i+1);
}
void PutQueenRook(int idxR,int Queen,int Rook){
  if(idxR==QRcnt){ Bishop_Count(); return; }
  short nowR=now_row[idxR];      // 根據now_row[idx]轉為目前是#Row
  for(short i=0;i<Board_Len;i++) //枚舉每個Column，選擇沒被佔走的放上棋子
    if(!Col[i]){
      Col[i]=1;
      // PutQueen：把兩側的對角線方程式數值設定成Board_Len
      if(Queen>0 and !NS[nowR+i] and !PS[nowR-i]){
        NS[nowR+i]=PS[nowR-i]=Board_Len;
        PutQueenRook(idxR+1,Queen-1,Rook);
        NS[nowR+i]=PS[nowR-i]=0;
      }
      // PutRook：把兩側的對角線方程式數值+1, 這樣回朔時-1
      if(Rook>0 and NS[nowR+i]<Board_Len and PS[nowR-i]<Board_Len){
        NS[nowR+i]++, PS[nowR-i]++;
        PutQueenRook(idxR+1,Queen,Rook-1);
        NS[nowR+i]--, PS[nowR-i]--;
      }
      Col[i]=0;
    }
}
void Bishop_Count(){

  fill(Row,Row+Board_Len,0); // 將PutQueenRook時的#Row標示為已經選取的狀態
  long status=0;
  for(short i=0;i<QRcnt;i++)
    Row[ now_row[i] ]=1;
  // init
  for(short i=0;i<(Board_Len<<1);i++) // 清空每個#NS的選項
    Slash_pick[i].clear();
  // 枚舉棋盤的所有格子，對於『合法空格』依序分配到對應的#NS作為選項
  for(int r=0;r<Board_Len;r++)
    if(!Row[r])
      for(int c=0;c<Board_Len;c++)
        if(!Col[c] and !NS[r+c] and !PS[r-c])
          Slash_pick[r+c].push_back(r-c);
  // 紀錄有『選項』的#NS
  white.clear();
  black.clear();
  for(int i=0;i<(Board_Len<<1);i++)
    if(Slash_pick[i].size())
      (i&1)? black.push_back(i): white.push_back(i);

  memset(whiteCnt,0,sizeof(whiteCnt));
  memset(blackCnt,0,sizeof(blackCnt));
  PutBishop(0,0,white,whiteCnt);
  PutBishop(0,0,black,blackCnt);

  for(int i=0;i<=Bcnt;i++)
    ans_cnt+=whiteCnt[i]*blackCnt[Bcnt-i];
}
void PutBishop(int idxS,int Bishop,vector<short> &Slash_memo,long *cnt){
  if(idxS==Slash_memo.size()){ cnt[Bishop]++; return; }
  PutBishop(idxS+1,Bishop,Slash_memo,cnt);
  short nowS=Slash_memo[idxS];
  for(short i=0;i<Slash_pick[nowS].size();i++)
    if(!PS[ Slash_pick[nowS][i] ])
      PS[ Slash_pick[nowS][i] ]=1,
      PutBishop(idxS+1,Bishop+1,Slash_memo,cnt),
      PS[ Slash_pick[nowS][i] ]=0;
}
