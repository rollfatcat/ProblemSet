// 題解：https://www.pttdata.com/ResponesPage.php?u=/bbs/C_and_CPP/M.1424084048.A.7F3.html
/* 標準解是 Cartesian Tree，以下是另一種解法：https://ideone.com/dwEeRp
 * 發現在一個子樹之中，總是最先輸入的節點當 root 。
 * 利用排序可以得到 inorder traversal
 * 所以只要用排序拿到中序尋訪的順序，再抓出 root 將整個陣列切成兩半。
 * 需要的"零件"就是在O(㏒n)時間抓出root。
 * RMQ 在O(㏒N)找 Root => SegmentTree( 0.1s/3.3MB )
 */
#include<bits/stdc++.h>
using namespace std;

const int maxN=131072;
int N, segtr[maxN<<2], qL, qR;
struct nn{
  int order,num;
  bool operator<(const nn &other)const{ return num<other.num; }
}node[maxN];
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
void BuildSegTr(int nL,int nR,int pt){
  // ---底層是大小順序(對映於number)---
  if(nL==nR){ segtr[pt]=nL; return; }
  int mid=(nL+nR)>>1, Lson=pt<<1;
  BuildSegTr(   nL,mid,  Lson);
  BuildSegTr(mid+1, nR,Lson+1);
  // ---比對時是取輸入順序( node[x].order )但紀錄時是紀錄排序後的大小位置 ---
  segtr[pt]=( node[segtr[Lson]].order<=node[segtr[Lson+1]].order )?segtr[Lson]:segtr[Lson+1];
}
int Query(int nL,int nR,int pt){
  if(qL<=nL and nR<=qR) return segtr[pt];
  int mid=(nL+nR)>>1, Lson=pt<<1;
  // ---查詢區間落在左子樹---
  if(qR<=mid) return Query(   nL,mid,  Lson);
  // ---查詢區間落在右子樹---
  if(qL >mid) return Query(mid+1, nR,Lson+1);
  // ---查詢區間需要遞迴求解---
  int pL=Query(   nL,mid,  Lson),
      pR=Query(mid+1, nR,Lson+1);
  return (node[pL].order<=node[pR].order)?pL:pR;
}
void fake_preorder(int nL,int nR){
  qL=nL, qR=nR;
  int root_pos=Query(0,N-1,1);
  printf("%d ",node[root_pos].num);
  if(nL<root_pos) fake_preorder(nL,root_pos-1);
  if(nR>root_pos) fake_preorder(root_pos+1,nR);
}
int main(){
  while(scanInt(N)){
    for(int i=0;i<N;i++)
      node[i].order=i, scanInt(node[i].num);
    sort(node,node+N);
    // 這篇的重點技巧：---根據輸入順序作為判斷的依據建樹---
    memset(segtr,0,sizeof(segtr));
    BuildSegTr(0,N-1,1);
    fake_preorder(0,N-1);
    puts("");
  }
}