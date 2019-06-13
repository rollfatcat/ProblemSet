// 中國餘式定理(週期之間兩兩互質 => 乘法反元素存在)
/* ｘ＋ｄ ≡ peak[0] (mod２３)
 * ｘ＋ｄ ≡ peak[1] (mod２８)
 * ｘ＋ｄ ≡ peak[2] (mod３３)
 * ｘ≡ peak[0]×５５４４＋peak[1]×１４４２１＋peak[2]×１２８８－ｄ(mod 21252)
 */
#include<bits/stdc++.h>
using namespace std;

int InverseMOD(int x,int mod){
  x%=mod;
  int mat[2][2]={{1,0},{0,1}}, num[2]={mod,x};
  bool now=0, nxt;
  for(int t; num[0] and num[1]; num[now]%=num[nxt],now=nxt){
    nxt=now^1;  t=num[now]/num[nxt];
    mat[now][0]-=t*mat[nxt][0],
    mat[now][1]-=t*mat[nxt][1];
  }
  if(mat[now][1]<0) mat[now][1]+=mod;// 確保乘法反元素是正的
  return mat[now][1];
}

int main(){
  int cycle[3]={23,28,33};
  int peak[3], aft;
  // 根據中國餘式定理找到對應的係數
  int coff[4];
  coff[0]=InverseMOD(cycle[1]*cycle[2],cycle[0])*cycle[1]*cycle[2];
  coff[1]=InverseMOD(cycle[0]*cycle[2],cycle[1])*cycle[0]*cycle[2];
  coff[2]=InverseMOD(cycle[0]*cycle[1],cycle[2])*cycle[0]*cycle[1];
  coff[3]=cycle[0]*cycle[1]*cycle[2];
  // Main Function
  for(int caseN=1;true;caseN++){
    scanf("%d %d %d %d",&peak[0],&peak[1],&peak[2],&aft);
    if(peak[0]<0) break;
    int ans=(coff[0]*peak[0]+coff[1]*peak[1]+coff[2]*peak[2])%coff[3];
    ans-=aft;
    if(ans<=0) ans+=coff[3];
    printf("Case %d: the next triple peak occurs in %d days.\n",caseN,ans);
  }
}
/*
0 0 0 0
0 0 0 100
5 20 34 325
4 5 6 7
283 102 23 320
203 301 203 40
-1 -1 -1 -1
*/