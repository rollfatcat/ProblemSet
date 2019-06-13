// P-Median Problem(演算筆記：http://www.csie.ntnu.edu.tw/~u91029/LocationAllocationProblem.html#2)

#include<bits/stdc++.h>
using namespace std;
#define MAXN 201
#define MAXP 31

const long INF=(long)1<<60;
long pos[MAXN];
long sum[MAXN];
long dis[MAXN][MAXN];
long dpn[MAXP][MAXN];
int  cut[MAXP][MAXN];   // 記錄最佳的分界線位置：cut[p][n]～n 屬於同一個區間

void PrintDFS(int p,int now){
  if(p==0 or now==0) return;
  PrintDFS(p-1,cut[p][now]-1);
  int M=cut[p][now]+now>>1;
  printf("Depot %d at restaurant %d serves",p,M);
  (cut[p][now]==now)? printf(" restaurant %d\n",now) :printf(" restaurants %d to %d\n",cut[p][now],now);
}
int main(){
  int N, P;

  for(int caseN=1;scanf("%d%d",&N,&P) and N;caseN++){
    for(int i=1;i<=N;i++)
      scanf("%ld",&pos[i]);
    // 根據最左邊的端點視為原點，推算其他點的相對距離並累計前綴和
    for(int i=2;i<=N;i++)
      pos[i]-=pos[1],
      sum[i]=sum[i-1]+pos[i];
    //記得算完後將最左邊的點座標標記為原點
    pos[1]=0;

    // 枚舉端點，計算(L,R)區間內的曼哈頓距離(利用前綴和加快計算，避免用for迴圈算) => 26ms vs 0.4s
    for(int L=1;L<=N;L++)
      for(int M,R=L;R<=N;R++)
        M=L+R>>1,
        dis[L][R]=pos[M]*(M-L)-sum[M-1]+sum[L-1]+sum[R]-sum[M]-pos[M]*(R-M);

    // 動態規劃
    memset(cut,0,sizeof(cut));
    for(int n=1;n<=N;n++)
      dpn[1][n]=dis[1][n],
      cut[1][n]=1;
    for(int p=2; p<=P; p++)
      for(int n=1; n<=N; n++){
        dpn[p][n]=INF;
        //int st=max(p,max(cut[p][n-1],cut[p-1][n]));
        for(int i=p; i<=n; i++)
          if(dpn[p-1][i-1]+dis[i][n]<dpn[p][n])
          dpn[p][n]=dpn[p-1][i-1]+dis[i][n],
          cut[p][n]=i;
      }
    // 依照格式輸出，BackTrace
    printf("Chain %d\n",caseN);
    PrintDFS(P,N);
    printf("Total distance sum = %ld\n\n",dpn[P][N]);
  }
}
/*
6 3
5
6
12
19
20
27
*/