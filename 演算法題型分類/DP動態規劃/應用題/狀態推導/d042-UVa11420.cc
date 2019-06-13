// 類似 d624燈泡問題：現在的狀態會影響到下一次的狀態
// 但是燈泡只要存一個狀態是連續N個暗燈以及現在選擇的狀態疊加後會不會跳開(不考慮窮舉暗燈數量上限)
#include<iostream>
#include<cstring>
using namespace std;

int main(){
  long DP[66][66][2]={}; //DP[櫃子全部數量][安全櫃子數量][現在狀態]=方法數, 0：未鎖 1：鎖上
  DP[1][0][0]=1, DP[1][1][1]=1;
  for(int all=1;all<=64;all++)
    for(int safe=0;safe<=all;safe++) // 現在狀態轉 變為 下一個狀態
      DP[all+1][ safe ][0]+=DP[all][safe][0], // UU
      DP[all+1][ safe ][1]+=DP[all][safe][0], // UL
      DP[all+1][ safe ][0]+=DP[all][safe][1], // LU
      DP[all+1][safe+1][1]+=DP[all][safe][1]; // LL

  for(int all,safe; scanf("%d %d",&all,&safe)==2 and all>0; )
    printf("%ld\n",DP[all][safe][0]+DP[all][safe][1]);
}