// 輪廓線(哈密頓圈覆蓋整個地圖)DP基本題
// https://fancydreams.ink/2018/06/20/%E5%A4%B4%E6%8F%92dp%E6%8C%87%E5%8C%97/
// https://hk.saowen.com/a/05e4d4af0a1d9dae9c95455fa8666f707f66fe5ef4772cd1b3c2acc3ea33bd59

#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 12

int N, M, base=1000000007;
bool map[MaxN][MaxN];
long long int DP[MaxN][MaxN][1<<MaxN];
int main(){
  int T, cnt;
  char ch;

  cin>>T;
  for(int caseNum=1;caseNum<=T;caseNum++){
    cin>>N>>M;
    for(int i=1;i<=N;i++)
      for(int j=1;j<=M;j++)
        cin>>ch,  map[i][j]=(ch=='1');
    // 初始狀態是 DP[1][0][0]=1, 倒退回前一列就是DP[0][M][0]
    DP[0][M][0]=1;
    // 一格一格的推演, 所以窮舉每一格和他們的輪廓線的狀態
    for(int i=1;i<=N;i++){
       // 複製上一層的狀態到這一層, 但是注意狀態複製和上下層輪廓線之間的關係
      for(int nowS=0;nowS<(1<<M);nowS++) // 上下層疊和的部分是 Top[0:M]=Down[1:M+1]
        DP[i][0][nowS<<1]=DP[i-1][M][nowS];
      // 窮舉同一列的每個格子以及每組的輪廓線
      for(int j=1;j<=M;j++){
        int aPut=1<<(j-1), bPut=1<<j;
        for(int nowS=0;nowS<(1<<(M+1));nowS++){
          bool PaStatus=(nowS&aPut), PbStatus=(nowS&bPut);
          if(map[i][j]){ //這一格格子是有線經過, 原先需討論3種狀況, 但前兩種屬於1對1對應且對應方式相同
            if(PaStatus^PbStatus) // (3)pa=1 or pb=1, 有上方或是左方會有1條線經過 => pa'=1 or pb'=1
              DP[i][j][nowS]=DP[i][j-1][nowS]+DP[i][j-1][nowS^aPut^bPut];
            else // (1)pa=pb=1 => pa'=pb'=0 (2)pa=pb=0 => pa'=pb'=1
              DP[i][j][nowS]=DP[i][j-1][nowS^aPut^bPut];
          } else { //這一格格子是插座,不能有任何的線經過, (pa,pb)只能是(0,0), 不然方法數就是0
            DP[i][j][nowS]=(!PaStatus and !PbStatus)?DP[i][j-1][nowS]:0;
          }
        }
      }
    }
    // 結果輸出, 最底層格子的(pa,pb)只可能是(0,0),所以輸出狀態 0000000..
    cout<<"Case "<<caseNum<<": "<<DP[N][M][0]%base<<endl;
  }
}