// 題目等同 d664-UVa11725(v0：67ms/v1：14ms)
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
#define mod 1000000007

int R, C, nowR;
long DP[2][78125]; // 78125=5^7
bool BitMask[7][7], nowBR, preBR;

struct nn{int pre,now;};
vector<nn> link[5][5];
void init_DFS(int Col,int nowS){
  if(Col==C){ DP[0][nowS]=1; return; }
  if(!BitMask[0][Col]){ //能上色時就一定畫
    for(int i=1;i<=4;i++)
      if(i!=(nowS%5))
        init_DFS(Col+1,5*nowS+i);
  } else //不能上色時格子的顏色只能選狀態0
    init_DFS(Col+1,5*nowS);
}
void Row_DFS(int Col,int preS,int nowS){
  if(Col==C){ DP[nowBR][nowS]=(DP[nowBR][nowS]+DP[preBR][preS])%mod; return; }
  int C1=preS%5, C2=nowS%5;
  if(!BitMask[nowR][Col]){
    if(!BitMask[nowR-1][Col]){ //(C3,C4)能上色
      for(int i=0;i<link[C1][C2].size();i++)
        Row_DFS(Col+1, 5*preS+link[C1][C2][i].pre, 5*nowS+link[C1][C2][i].now);
    }else{ // C3不能上色但C4可以
      for(int i=1;i<=4;i++)
        if(i!=C2)
          Row_DFS(Col+1, 5*preS, 5*nowS+i);
    }
  }else{
    if(!BitMask[nowR-1][Col]){ // C3可以上色但C4不能
      for(int i=1;i<=4;i++)
        if(i!=C1)
          Row_DFS(Col+1, 5*preS+i, 5*nowS);
    }else // C3和C4都不能上色
      Row_DFS(Col+1, 5*preS, 5*nowS);
  }
}
int main(){
  //產生配對
  /*   C1 C3 <= pre
   *   C2 C4 <= now
   */
  for(int C1=0; C1<=4; C1++)
    for(int C2=0; C2<=4; C2++)
      for(int C3=1; C3<=4; C3++)
        for(int C4=1; C4<=4; C4++){
          if( (C1>0 and (C1==C2 or C1==C3)) or C2==C4 or C3==C4 ) continue;
          link[C1][C2].push_back( {C3,C4} );
        }
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int T, cnt;
  cin>>T;
  for(int caseNum=1; caseNum<=T; caseNum++){
    cin>>R>>C>>cnt;
    R++, C++; // R/C代表劃幾刀,會產生(R+1)x(C+1)個區域
    memset(BitMask,0,sizeof(BitMask));
    for(int x, y; cnt--; )
      cin>>x>>y,  BitMask[x-1][y-1]=1;
    int maxS=pow(5,C);
    memset(DP[0],0,sizeof(DP[0]));
    init_DFS(0,0), nowBR=0;// 初始化
    for(nowR=1;nowR<R;nowR++){
      nowBR=nowR&1, preBR=1^nowBR;
      memset(DP[nowBR],0,sizeof(DP[0]));
      Row_DFS(0,0,0);
    }
    int cnt=0;
    for(int i=0;i<maxS;i++)
      cnt=(cnt+DP[nowBR][i])%mod;
    cout<<"Case "<<caseNum<<": "<<cnt<<endl;
  }
}