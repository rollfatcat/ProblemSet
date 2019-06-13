// 看得出來會用到 DisjointSet來做，但當某個號碼沒有特定分組時...
// 題解：https://sites.google.com/site/silithusxoi/code/ks2015
/* (1) 組內各同學的籤號均已指定(即不包含0)，此時組內同學必呈環狀結構，如範例一：1→2→3→1、4→5→4，這些組不能跟其他組別合併，因此必須佔用一個分組配額，設這類組別有G1個。
 * (2) 組內有一名同學的籤號未指定(即包含0)，這些組可以跟其他組別合併，如範例二第二筆測資：4→2→1→0、3→0、5→0，設這類組別有G2個。
 * 此題真正需要計算的是：把G2組恰好分成M-G1組、且該M-G1組內同學呈環狀結構的組合數。可應用『第一類STIRling數』快速求解出這個組合數。
 * 斯特靈數(STIRlingNum)的遞推關係的說明：
 * 考慮第n個物品，n可以單獨構成一個非空循環排列，這樣前n-1種物品構成k-1個非空循環排列，有s(n-1,k-1)}種方法；
 * 前n-1種物品構成k個非空循環排列，而第n個物品插入第i個物品的左邊，這有(n-1)*s(n-1,k)}種方法。
 *
 */
#include<bits/stdc++.h>
using namespace std;

const int mod=1000007;
int STIR[1001][1001], parent[1001];
int haszero[1001];
inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int StirlingNum(int G,int M){
  if(G<0 or M<0) return 0;
  if(STIR[G][M]==-1)
    STIR[G][M]=(StirlingNum(G-1,M-1)+(G-1)*StirlingNum(G-1,M)%mod)%mod;
  return STIR[G][M];
}
int find_parent(int x){//有沒有做扁平化不影響時間
  if(x!=parent[x])
    parent[x]=find_parent(parent[x]);
  return parent[x];
}
int main(){
  int T, N, M;
  int b, pb, pa;
  for(scanInt(T);T--;){
    scanInt(N), scanInt(M);
    // inits
    memset(STIR,0xff,sizeof(STIR));
    STIR[0][0]=STIR[1][1]=1;
    for(int i=1;i<=N;i++)
      parent[i]=i, haszero[i]=0, STIR[i][0]=0;
    // DisjointSet
    for(int i=1;i<=N;i++){
      scanInt(b);
      if(b){ //有指定對象時則合併自己和指定對象，沒有時則紀錄0的個數
        //for(pa=parent[i]; pa!=parent[pa]; pa=parent[pa]);
        //for(pb=parent[b]; pb!=parent[pb]; pb=parent[pb]);
        pa=find_parent(i),
        pb=find_parent(b);
        if(pa!=pb) // 合併：把對方指向自己，自己是對方的父結點，自己有沒有0繼承對方
          parent[pb]=pa,  haszero[pa]|=haszero[pb];
      } else{
        //for(pa=parent[i]; pa!=parent[pa]; pa=parent[pa]);
        haszero[find_parent(i)]++;
      }
    }
    int G2=0;
    for(int i=1;i<=N;i++)
      if(parent[i]==i)
        if(haszero[i]) G2++;
        else M--;
    // STIRling Number
    printf("%d\n",StirlingNum(G2,M));
  }
}