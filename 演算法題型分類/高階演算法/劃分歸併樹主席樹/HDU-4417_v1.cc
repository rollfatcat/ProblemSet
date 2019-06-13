// 題解：https://blog.csdn.net/gyhguoge01234/article/details/78161299
/* 主席樹解法(支援在線查詢)
 * 因為 H 有單調性所以本來靜態的問題我們變成用動態的線段樹來處理，但犧牲的是我們把時間這個維度拿掉了，
 * 也就是我們變成要離線查詢，不能動態查詢。像在IOI這種比賽的時候時常是不允許離線查詢的，
 * 因此在這裡我們要來講一種方法可以做到在線查詢，就是這一段的標題，持久化線段樹。
 * 持久化就是要把歷史版本全部還原回來，我們可以用少量的空間來達到能將所有舊的線段樹都還原，
 * 原理是因為每次線段操作修改到的只有大概 O(㏒n) 這麼多的節點，所以我們只要把有更動到的節點儲存起來就可以還原這個歷史版本。
 * 把H這個維度用持久化線段樹儲存起來後，我們的時間維度就又變成自由的了，因此我們就可以做到動態查詢。
 * 時間:O(n㏒n+Q㏒n) 空間:O(n㏒n)
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001

int N, Q, uN;
int lson[MAXN<<5]; // 通常節點的數量大約是20倍～50倍
int rson[MAXN<<5];
int Ncnt[MAXN<<5];
int root[MAXN];
int org[MAXN];
int srt[MAXN];
int tot, tag;

void update(int nL,int nR,int &now,int pre){
  now=++tot;
  lson[now]=lson[pre];
  rson[now]=rson[pre];
  Ncnt[now]=Ncnt[pre]+1;
  if(nL==nR) return;
  int nM=nL+nR>>1;
  (tag<=nM)? update(nL,nM,lson[now],lson[pre]): update(nM+1,nR,rson[now],rson[pre]);
}
int query(int nL,int nR,int Lv,int Rv){
  if(nR<=tag) return Ncnt[Rv]-Ncnt[Lv];
  int nM=nL+nR>>1;
  int ret=query(  nL,nM,lson[Lv],lson[Rv]);
  if(tag>nM ) ret+=query(nM+1,nR,rson[Lv],rson[Rv]);
  return ret;
}
void showTree(int nL,int nR,int now){
  printf("%d %d %d %d\n",now,Ncnt[now],lson[now],rson[now]);
  if(nL==nR) return;
  int nM=nL+nR>>1;
  showTree(nL,nM,lson[now]);
  showTree(nM+1,nR,rson[now]);
}

int main(){
  int caseT, qL, qR, qH;
  scanf("%d",&caseT);
  for(int caseN=1;caseN<=caseT;caseN++){
    scanf("%d%d",&N,&Q);
    // 原始資料讀取
    for(int i=0;i<N;i++)
      scanf("%d",&org[i]),
      srt[i]=org[i];
    // 離散化
    sort(srt,srt+N);
    uN=unique(srt,srt+N)-srt;
    // root[0]=0 代表一棵空的線段樹
    tot=0;
    // 對每個單點的原始資料去更新線段樹直到每個葉節點，並記錄整條路徑上的節點
    for(int i=0;i<N;i++)
      tag=lower_bound(srt,srt+uN,org[i])-srt,
      update(0,uN-1,root[i+1],root[i]);

    printf("Case %d:\n",caseN);
    while(Q--)
      scanf("%d%d%d",&qL,&qR,&qH),
      tag=upper_bound(srt,srt+uN,qH)-srt-1,
      printf("%d\n",(tag>=0)? query(0,uN-1,root[qL],root[qR+1]): 0);

  }
}
/*
1
10 10
0 5 2 7 5 4 3 8 7 7
2 8 6
3 5 0
1 3 1
1 9 4
0 1 0
3 5 5
5 5 1
4 6 3
1 5 7
5 7 3
*/