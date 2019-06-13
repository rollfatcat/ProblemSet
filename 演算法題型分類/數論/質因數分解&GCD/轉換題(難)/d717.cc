// (難度極高的加強題)DFS剪枝＋搜索優化
/* 當 nR-nL 小的時候，直接遍歷搜索即可，以下程式碼先暫定 1e5 為界線。
 * 當 nR-nL 大的時候，我們開始窮舉該數字的質因數，從小到大開始窮舉，
 * 2 有 0, 1, 2, ... 3 有 0, 1, 2, ... 類推，剪枝的條件，
 * 我們先假設搜索狀態 (pi, num, tot) 當前質因數 pi，當前枚舉數字 num, num 所擁有的因數個數，
 * 剩餘最多因數估計 q=[ log(U/num)/log(pi) ]，能湊成的個數即是 pow(2,q)，
 * 如果 tot*pow(2,q)<目前最多個數的因數時，則回傳。
 * 此外當 (nL-1)/num == nR/num 時，即是無法達到該區間內，就可以回傳了。
 * 為了加速 DFS 的剪枝，我們可以預先找倒數 500 個數字的最多因數個數，好讓 DFS 在此之前快速剪枝。
 */
#include<bits/stdc++.h>
using namespace std;
#define Threshold 1e4

vector<int> prime;
int N ,nL, nR;
int Nrec, Nmax, Ntmp;

inline void seive(int bound){
  vector<bool> NotPrime(bound+1,0);
  for(int i=4;i<=bound;i+=2)
    NotPrime[i]=true;
  for(int i=3;i<=sqrt(bound);i+=2)
    if(NotPrime[i]==0)
      for(int j=3;i*j<=bound;j+=2)
        NotPrime[i*j]=true;
  prime.emplace_back(2);
  for(int i=3;i<=bound;i+=2)
    if(NotPrime[i]==0)
      prime.emplace_back(i);
}
inline int FactorCount(int x,long ret=1){
  for(int p,i=0;i<prime.size() and x>=prime[i];i++){
    for(p=0;x%prime[i]==0;x/=prime[i],p++);
    ret*=p+1;
  }
  return (x>1)?(ret<<1):ret;
}

void DFS_Search(int idx,long num,int tot){ // idx：第N個質數，num：目前的數字，tot：因數個數
  if(nR/num==nL/num) return; // 範圍內不存在任何數字
  if(idx>=prime.size())  return; // 範圍內的質數用完
  if(num>=nL and tot>Nmax or (tot==Nmax and num<Nrec)) // 更新最佳紀錄，需要保證更新時的num落在範圍內
    Nrec=num, Nmax=tot;
  // 剪枝：從現在的數值到最大值之間以目前在的質數估算還有多少的指數成長空間
  // 這樣的估計方式(高估)是最大化因數的個數(比方說：q=3，最佳分配是後面連乘3個相異的質數，實際上不一定在範圍內)
  // 實作細節是利用cmath的log和換底公式，必須保持精確度所以要轉換成 double 型態
  int q=log((double)nR/num)/log(prime[idx]);
  if(tot*(1<<q)<Nmax or (tot*(1<<q)==Nmax and num>=Nrec) ) return;

  for(int p=1; num<=nR; p++,num*=prime[idx])
    DFS_Search(idx+1, num, tot*p);
}
int main(){
  // 埃式篩法：建立判斷最大範圍內質數所需的質數表
  seive(sqrt(2147483647));
  //
  scanf("%d",&N);
  while(N--){
    scanf("%d%d",&nL,&nR);
    if(nR-nL>=Threshold){ // 大區間先預跑500個便於快速剪枝
      Nrec=nR,
      Nmax=FactorCount(Nrec);
      for(int i=1;i<=500;i++)
        if( (Ntmp=FactorCount(nR-i))>Nmax)
          Nmax=Ntmp, Nrec=nR-i;
      DFS_Search(0,1,1);
    }
    else{ // 小區間：線性搜尋
      Nrec=nL,
      Nmax=FactorCount(nL);
      for(int Nnow=nL+1;Nnow<=nR;Nnow++)
        if( (Ntmp=FactorCount(Nnow))>Nmax)
          Nmax=Ntmp, Nrec=Nnow;
    }
    printf("Between %d and %d, %d has a maximum of %d divisors.\n",nL,nR,Nrec,Nmax);
  }
}
/*
4
1 10
1000 1000
999999900 1000000000
1 2147483647
*/