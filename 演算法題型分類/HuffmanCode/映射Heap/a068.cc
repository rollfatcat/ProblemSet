/* 原題型是 NPSC2009初賽題的PE，但USB數量無法用線性搜尋決定置換誰O(M)
 * 實作 MaxHeap 的 Insert 和 Delete，兩個時間都得壓在O(㏒M)
 * 用映射方式找到要改動節點的值O(1)並重新排序(HeapUp：O(㏒M)), 新的值一定比舊的大所以是向上挑戰
 * Greedy + Mapping-Heap
 * Greedy：每次都置換『下一次用到同一個DISK的時機點』中最晚的
 * Mapping-Heap：維護MAX-HEAP，排序方式是依照『下一次用到同一個DISK的時機點』
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6;
const int MAXM=1e4;
const int MAXD=1e5+1; //  0 ≤ 硬碟編號 ≤ 1e5
int N, M, HeapCnt;
int DISK[MAXD];
struct episode{ int dsk,nxt; } ESP[MAXN], HEAP[MAXM];

inline void scanInt(int &x){char c;for(x=0;(c=getchar_unlocked())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
inline void HeapSwap(int,int);
inline void HeapAdd(episode);
inline void HeapUp(int);
inline void HeapDelete();
int main(){
  int caseT;
  scanInt(caseT);
  while(caseT--){
    scanInt(N),
    scanInt(M);
    for(int i=0;i<N;i++)
      scanInt(ESP[i].dsk);
    fill(DISK,DISK+MAXD,MAXN);
    for(int i=N-1;i>=0;i--)
      ESP[i].nxt=DISK[ ESP[i].dsk ],
      DISK[ ESP[i].dsk ]=i;
    // 初始化：DISK 映射到 HEAP 位置預設值是0
    fill(DISK,DISK+MAXD,0);
    HeapCnt=0;

    int Heap_pos;
    int ans_cnt=0;
    for(int i=0;i<N;i++){
      if( DISK[ ESP[i].dsk ]>0 ) // 現在這個硬碟插在USB，更新HEAP中的nxt後調整HEAP
        Heap_pos=DISK[ ESP[i].dsk ],
        HEAP[ Heap_pos ].nxt=ESP[i].nxt,
        HeapUp(Heap_pos);
      else if(HeapCnt<M)
        HeapAdd(ESP[i]);
      else
        HeapDelete(),
        HeapAdd(ESP[i]),
        ans_cnt++;
    }
    printf("%d\n",ans_cnt);

  }
}
void HeapSwap(int a,int b){
  swap(HEAP[a],HEAP[b]);
  DISK[ HEAP[a].dsk ]=a,
  DISK[ HEAP[b].dsk ]=b;
}
void HeapUp(int now_pos){
  for(int pa_pos; now_pos>1; now_pos=pa_pos){
    pa_pos=now_pos>>1;
    if(HEAP[pa_pos].nxt>=HEAP[now_pos].nxt)
      break;
    HeapSwap(now_pos,pa_pos);
  }
}
void HeapAdd(episode nowESP){
  HEAP[++HeapCnt]=nowESP,
  DISK[nowESP.dsk]=HeapCnt,
  HeapUp(HeapCnt);
}
void HeapDelete(){
  DISK[ HEAP[1].dsk ]=0;
  HEAP[1]=HEAP[HeapCnt--];
  for(int nxt_pos,now_pos=1; (nxt_pos=now_pos<<1)<=HeapCnt; now_pos=nxt_pos){
    if(nxt_pos+1<=HeapCnt and HEAP[nxt_pos].nxt<HEAP[nxt_pos+1].nxt)
      nxt_pos++;
    if(HEAP[now_pos].nxt>=HEAP[nxt_pos].nxt)
      break;
    HeapSwap(now_pos,nxt_pos);
  }
}
/*
2
5 3
5 4 3 2 1
20 5
1 2 3 4 5 4 3 2 6 7 8 9 8 7 6 11 12 13 1 2
===
第二筆測資發生交換的時間點：
8 9 10 11 15 16 17 19
*/