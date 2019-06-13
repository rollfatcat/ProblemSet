// 這些緞帶可以裁剪成適當的長度來製作花飾，所以一條緞帶可以製作二個以上的花飾。
// 但緞帶無法拼接，所以若所剩之緞帶長度不足以製作花飾時只好捨棄。
/* 多重背包問題
 * 10 ≦ N ≦ 500，0 ≦ Ci ≦ 1000
 */

#include<bits/stdc++.h>
using namespace std;

int sz[9]={8,16,24,32,40,48,56,64,80};
int uL, cnt[9]={};

int main(){

  bool fail=false;
  scanf("%d",&uL);
  for(int i=0;i<9;i++){
    scanf("%d",&cnt[i]);
    fail|=(cnt[i] and sz[i]>uL);
  }
  if(fail){ puts("NO SOLUTION!!"); return 0; }
  int need=0, now_rem, now_cnt;
  for(int i=8;i>=0;i--){
    now_cnt=uL/sz[i];
    now_rem=uL%sz[i];
    need+=now_cnt;
    for(int j=i-1;j>=0;j--){
      if(rem<sz[j]) continue;
      now_cnt=rem/sz[j];
      now_rem=rem%sz[i];
    }
  }
}