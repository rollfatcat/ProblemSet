/* ZJ-d543 + ZJ-b510 + ZJ-a682 + zobrist hash_map + 鏡像/旋轉的等價盤面
 * 利用Hash_Map紀錄已經算過的棋盤，記錄等價的(鏡像/旋轉)越多可能可以節省時間但查詢成本也會增加
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 10

long ans_cnt;
short Qcnt, Rcnt, Bcnt;
short Board_Len, QRcnt;

short rem_statusR;     //+0 - +9 => 位元表示(狀態壓縮)
short nslash[MAXN<<1]; //+0 - +9
short pslash[MAXN<<1]; //-9 - +9
short *NS=&nslash[0];  // x+y：/
short *PS=&pslash[9];  // x-y：\

vector<short> Slash_pick[MAXN<<1]; // 紀錄#NS的『選項』:-9 - +9
long whiteCnt[11];
long blackCnt[10];

// Zobrist就是一种非常有效的将局面映射为一个独特的哈希值的方法。
// 对于任何一个不同的局面，其使用Zobrist所算出来的哈希值是完全不同的
long zobrist[MAXN*MAXN]={};
map<long,long> record;

// Row從(0,N-1)中選取QRcnt個當作Queen和Rook要放的#Row
void New_QueenRookMap(short now,short st,short statusR);

// 枚舉選取的Row依序放入Queen或是Rook
void PutQueenRook(short statusR,short statusC,short Queen,short Rook);

// 將棋盤轉45度後枚舉#NS，對於每個#NS枚舉#PS
// 將奇偶數分開計算(因為不會互相干擾，證明請參考a682的動態規劃解法)
void Bishop_Count(short rem_statusC);
void PutBishop(int statusS,int Bishop,long *cnt);

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  // 哈希表權重(盤面唯一性)
  for(short i=0;i<100;i++)
    zobrist[i]=rand()|((long)rand()<<32);;
  while(cin>>Qcnt>>Rcnt>>Bcnt){

    QRcnt=Qcnt+Rcnt;
    Board_Len=QRcnt+Bcnt;

    record.clear();
    ans_cnt=0;
    New_QueenRookMap(0,0,0);

    cout<<ans_cnt<<endl;
  }
}
void New_QueenRookMap(short now,short st,short statusR){
  if(now==QRcnt){ // 已經「成功」選取QRcnt個#Row
    // init
    memset(nslash,0,sizeof(nslash));
    memset(pslash,0,sizeof(pslash));
    rem_statusR=((1<<Board_Len)-1)^statusR;
    // 枚舉每個選取的Row依序放入Queen和Rook
    PutQueenRook(statusR,(1<<Board_Len)-1,Qcnt,Rcnt);
    return;
  }
  for(short i=st;i<=Board_Len-QRcnt+now;i++)
    New_QueenRookMap(now+1,i+1,statusR|(1<<i));
}
void PutQueenRook(short statusR,short statusC,short Queen,short Rook){
  if(statusR==0){ Bishop_Count(statusC); return; }
  short nowC, nowR=__builtin_ctz(statusR);  // 根據 statusR 轉為目前是#Row
  for(short cPut,canPutQR=statusC; canPutQR; canPutQR^=cPut){ //枚舉每個Column，選擇沒被佔走的放上棋子
    cPut=canPutQR&-canPutQR,
    nowC=__lg(cPut);
    // PutQueen：把兩側的對角線方程式數值設定成Board_Len
    if(Queen>0 and !NS[nowR+nowC] and !PS[nowR-nowC]){
      NS[nowR+nowC]=PS[nowR-nowC]=Board_Len;
      PutQueenRook(statusR^(1<<nowR),statusC^cPut,Queen-1,Rook);
      NS[nowR+nowC]=PS[nowR-nowC]=0;
    }
    // PutRook：把兩側的對角線方程式數值+1, 這樣回朔時-1
    if(Rook>0 and NS[nowR+nowC]<Board_Len and PS[nowR-nowC]<Board_Len){
      NS[nowR+nowC]++, PS[nowR-nowC]++;
      PutQueenRook(statusR^(1<<nowR),statusC^cPut,Queen,Rook-1);
      NS[nowR+nowC]--, PS[nowR-nowC]--;
    }
  }
}
void Bishop_Count(short rem_statusC){
  // init
  for(short i=0;i<(Board_Len<<1)-1;i++) // 清空每個#NS的選項
    Slash_pick[i].clear();
  // 枚舉棋盤的所有格子，對於『合法空格』依序分配到對應的#NS作為選項
  // 掃描整個棋盤後，依照『合法空格』建立的Key做查表避免『重複計算』
  long status[8]={};
  short rShift, rPos, cShift, cPos;
  for(short statusR=rem_statusR; statusR; statusR^=rShift){
    rShift=statusR&-statusR,
    rPos=__lg(rShift);
    for(short statusC=rem_statusC; statusC; statusC^=cShift){
      cShift=statusC&-statusC,
      cPos=__lg(cShift);
      if(!NS[rPos+cPos] and !PS[rPos-cPos])
        status[0]^=zobrist[rPos*Board_Len+cPos],
        Slash_pick[rPos+cPos].push_back(rPos-cPos);
    }
  }
  // 若查表後該盤面沒有計算過則拆成獨立區域後各自暴力法處理
  if(record.find(status[0])==record.end()){
    long tmp_cnt=0;
    int status_white=0; // 紀錄有『選項』的#NS(x+y=even)
    int status_black=0; // 紀錄有『選項』的#NS(x+y=odd)
    for(int i=0;i<(Board_Len<<1);i++)
      if(Slash_pick[i].size())
        (i&1)? status_black|=(1<<i): status_white|=(1<<i);

    memset(whiteCnt,0,sizeof(whiteCnt));
    memset(blackCnt,0,sizeof(blackCnt));
    PutBishop(status_white,0,whiteCnt);
    PutBishop(status_black,0,blackCnt);

    for(int i=0;i<=Bcnt;i++)
      tmp_cnt+=whiteCnt[i]*blackCnt[Bcnt-i];
    // 同時記錄鏡像和反轉的盤面狀態(8種)
    for(short statusR=rem_statusR; statusR; statusR^=rShift){
      rShift=statusR&-statusR,
      rPos=__lg(rShift);
      for(short statusC=rem_statusC; statusC; statusC^=cShift){
        cShift=statusC&-statusC,
        cPos=__lg(cShift);
        if(!NS[rPos+cPos] and !PS[rPos-cPos])
          status[1]^=zobrist[(Board_Len-1-rPos)*Board_Len+cPos],
          status[2]^=zobrist[rPos*Board_Len+(Board_Len-1-cPos)],
          status[3]^=zobrist[(Board_Len-1-rPos)*Board_Len+(Board_Len-1-cPos)],
          status[4]^=zobrist[cPos*Board_Len+rPos],
          status[5]^=zobrist[(Board_Len-1-cPos)*Board_Len+rPos],
          status[6]^=zobrist[cPos*Board_Len+(Board_Len-1-rPos)],
          status[7]^=zobrist[(Board_Len-1-cPos)*Board_Len+(Board_Len-1-rPos)];
      }
    }
    record[status[0]]=record[status[1]]=record[status[2]]=record[status[3]]=tmp_cnt,
    record[status[4]]=record[status[5]]=record[status[6]]=record[status[7]]=tmp_cnt;
  }
  ans_cnt+=record[status[0]];
}
void PutBishop(int statusS,int Bishop,long *cnt){
  if(statusS==0){ cnt[Bishop]++; return; }
  if(Bishop>Bcnt) return;
  int posS=__lg(statusS&-statusS);
  statusS^=(1<<posS);
  PutBishop(statusS,Bishop,cnt);
  for( short sPut:Slash_pick[posS] ){
    if(PS[sPut]==0)
      PS[sPut]=1,
      PutBishop(statusS,Bishop+1,cnt),
      PS[sPut]=0;
  }
}
/* t=7.98s
3 1 6
1 3 6
2 2 6
*/