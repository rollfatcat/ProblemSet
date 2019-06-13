/* 乍看之下不知道這題要求的Stack模擬和樹狀數組的關係(?)但知道竅門後算簡單
 * 用一個數组紀錄每個编號的電影現在所處的位置。然后用樹狀數组维護個數。
 */
#include<bits/stdc++.h>
using namespace std;

int BIT[200001]={};
int pos[100001]={};
inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
inline int lowbit(int x){ return -x&x; }
int main(){
  int caseN, N, Q, MAXN;
  for(scanInt(caseN);caseN--;){
    scanInt(N),
    scanInt(Q);
    MAXN=Q+N;
    /* 初始化時模擬Stack的疊放從位置Q+1開始放(前面先預留Q個空格)
     * 每次問某個號碼的碟片時根據映射表，更新這個位置的值(-1)後，
     * 做區域查詢(從開頭到現在這個位置的總數和)
     * 再從Q由後往前依序放到位置(更新映射表和BIT)
     */
    memset(BIT,0,sizeof(BIT));
    for(int i=1; i<=N; pos[i]=Q+i,i++)
      for(int j=Q+i; j<=MAXN; j+=lowbit(j))
        BIT[j]++;
    for(int qN; Q; Q--){
      scanInt(qN);
      // 根據映射表把那個位置和他父節點們的值都-1
      for(int j=pos[qN]; j<=MAXN; j+=lowbit(j))
        BIT[j]--;
      // 區域查詢：從頭到這個位置間的個數
      int sum=0;
      for(int j=pos[qN]; j; j-=lowbit(j))
        sum+=BIT[j];
      printf("%d",sum);
      // ---更新映射表和BIT---
      pos[qN]=Q;
      for(int j=Q; j<=MAXN; j+=lowbit(j))
        BIT[j]++;
      putchar((Q==1)?'\n':' ');
    }
  }
}
/*
2
3 3
3 1 1
5 3
4 4 5
*/