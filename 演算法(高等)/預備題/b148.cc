// 題目提到葉節點最多1024個，要求採後序輸出，所以可以一邊建樹一邊輸出結果字元
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1<<10;
int N;
char BST[MAXN<<2];
void PostOrder(int nL,int nR,int pt){
  if(nL==nR){
    scanf("%c",&BST[pt]);
    BST[pt]=(BST[pt]=='1')?'I':'B';
    printf("%c",BST[pt]);
    return;
  }
  int nM=(nL+nR)>>1, Lson=pt<<1, Rson=Lson|1;
  PostOrder(  nL,nM,Lson),
  PostOrder(nM+1,nR,Rson);

  BST[pt]=(BST[Lson]==BST[Rson])?BST[Lson]:'F';
  printf("%c",BST[pt]);
}
int main(){
  scanf("%d",&N); getchar();
  N=1<<N;
  PostOrder(0,N-1,1);
}