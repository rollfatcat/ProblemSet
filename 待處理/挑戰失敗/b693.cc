// 狀態壓縮的變形
// 70% 正確，問題在於有20%是TLE，初步估計是時間花在重複的if判斷
#include<bits/stdc++.h>
using namespace std;

int N, R, mod;
int color[16][16][2];
int RowColor[2][16];
int DP[2][(1<<16)-1]={};
vector<bool>pairLink[16][16][4]={};
bool nowR, preR;

void FirstRowCnt(int col,int nowS){
  if(col==N){ DP[0][nowS]=1; return; }
  if(RowColor[0][col-1]!=color[0][col][0])
    RowColor[0][col]=color[0][col][0], FirstRowCnt(col+1,nowS<<1);
  if(RowColor[0][col-1]!=color[0][col][1])
    RowColor[0][col]=color[0][col][1], FirstRowCnt(col+1,nowS<<1|1);
}
void PairLink(int nowS,int preS,int col){
  if(col==N){ DP[nowR][nowS]=(DP[nowR][nowS]+DP[preR][preS])%mod; return; }
  if(RowColor[preR][col-1]!=color[R-1][col][0]){
    RowColor[preR][col]=color[R-1][col][0];
    if(RowColor[preR][col]!=color[R][col][0] and RowColor[nowR][col-1]!=color[R][col][0])
      RowColor[nowR][col]=color[R][col][0], PairLink(  nowS<<1,preS<<1,col+1);
    if(RowColor[preR][col]!=color[R][col][1] and RowColor[nowR][col-1]!=color[R][col][1])
      RowColor[nowR][col]=color[R][col][1], PairLink(nowS<<1|1,preS<<1,col+1);
  }
  if(RowColor[preR][col-1]!=color[R-1][col][1]){
    RowColor[preR][col]=color[R-1][col][1];
    if(RowColor[preR][col]!=color[R][col][0] and RowColor[nowR][col-1]!=color[R][col][0])
      RowColor[nowR][col]=color[R][col][0], PairLink(  nowS<<1,preS<<1|1,col+1);
    if(RowColor[preR][col]!=color[R][col][1] and RowColor[nowR][col-1]!=color[R][col][1])
      RowColor[nowR][col]=color[R][col][1], PairLink(nowS<<1|1,preS<<1|1,col+1);
  }
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  while(cin>>N>>mod){
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
        cin>>color[i][j][0]>>color[i][j][1];
    // 1st Row 的狀態個數
    RowColor[0][0]=color[0][0][0], FirstRowCnt(1,0);
    RowColor[0][0]=color[0][0][1], FirstRowCnt(1,1);
    // 對Row和Row之間做狀態轉移
    for(R=1;R<N;R++){
      nowR=R&1, preR=nowR^1;
      memset(DP[nowR],0,sizeof(DP[0]));
      RowColor[preR][0]=color[R-1][0][0];
      if(RowColor[preR][0]!=color[R][0][0])  RowColor[nowR][0]=color[R][0][0], PairLink(0,0,1);
      if(RowColor[preR][0]!=color[R][0][1])  RowColor[nowR][0]=color[R][0][1], PairLink(1,0,1);
      RowColor[preR][0]=color[R-1][0][1];
      if(RowColor[preR][0]!=color[R][0][0])  RowColor[nowR][0]=color[R][0][0], PairLink(0,1,1);
      if(RowColor[preR][0]!=color[R][0][1])  RowColor[nowR][0]=color[R][0][1], PairLink(1,1,1);
    }
    //
    int cnt=0;
    nowR=(N-1)&1;
    for(int i=0;i<(1<<N);i++)
      cnt=(cnt+DP[nowR][i])%mod;
    cout<<cnt<<'\n';
  }
}
/*
2 101
7 8
1 5
7 8
7 8

3 101
1 2
1 3
2 3
3 1
2 1
2 1
4 1
2 5
6 7
*/