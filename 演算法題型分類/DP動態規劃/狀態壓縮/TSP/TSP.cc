// TSP演算法過程：http://episte.math.ntu.edu.tw/articles/mm/mm_11_3_02/page3.html
// 實作參考：https://blog.csdn.net/qq_39322743/article/details/79700051?utm_source=blogxgwz0
// morris821028的教學網誌 : http://mypaper.pchome.com.tw/zerojudge/post/1323281846
#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 22 //極限值
#define INF 0x7f7f7f7f

int n, N, map[MaxN][MaxN];
int DP[MaxN][1<<MaxN-1];
int Book[1<<MaxN+1]; // map查表(㏒N)會TLE,改用陣列查表O(1)
int GCD(int a,int b){ return(a%b)?GCD(b,a%b):b; }
int main(){
  for(int i=0;i<MaxN;i++)
    Book[1<<i]=i;

  while(cin>>n){
    // 讀取地圖, a->b ≠ b->a
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        cin>>map[i][j];
    int MaxS=(1<<n-1)-1; //
    memset(DP,0x7f,sizeof(DP));
    DP[0][0]=0;
    for(int i=1; i<n; i++)
      DP[i][0]=map[i][0];
    // Bottom-Up作法
    for(int nowS=1; nowS<MaxS; nowS++)//总共有n-1个点，但不能全部取
      for(int i=1;i<n;i++)//把1~(n-1)这n-1个点，映射为集合对应的二进制数中的
        if( !(nowS&(1<<i-1)) ) //i不在集合中
          for(int j=1;j<n;j++)
            if( nowS&(1<<j-1) ) //j在集合中
              DP[i][nowS]=min(DP[i][nowS], DP[j][nowS^(1<<j-1)]+map[i][j]);
    for(int i=0;i<n;i++,printf("\n"))
      for(int nowS=0;nowS<=MaxS;nowS++)
        if(DP[i][nowS]==0x7f7f7f7f) printf(" x ");
        else printf("%2d ",DP[i][nowS]);
    for(int i=1;i<n;i++) //上面只會至少有一個位置不會在集合中,所以需要這邊取所有解的最小
      DP[0][MaxS]=min(DP[0][MaxS],map[0][i]+DP[i][MaxS^(1<<i-1)]);
    cout<<DP[0][MaxS]<<endl;
  }
}
/*
4
0 3 9 7
3 0 6 5
5 6 0 6
9 7 4 0
4
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0

*/