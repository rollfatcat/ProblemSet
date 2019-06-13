// 原題型是 NPSC2009初賽題的PE, 但USB數量不大可以用線性搜尋決定置換誰O(M)
// 實作MaxHeap的Insert和delete, 兩個時間都得壓在O(logM)
// 用映射方式找到要改動節點的值O(1)並重新排序(Heap_up O(logM)), 新的值一定比舊的大所以是向上挑戰
#include<iostream>
#include<cstring>
using namespace std;

#define MaxUSBNum 10001
#define MaxDiskNum 100001
#define MaxEpNum 1000000
#define INF 0x7fffffff

struct Episode{ int disk, next; } E[MaxEpNum];
struct USB{ int disk, next; } Heap[MaxUSBNum], tmp;
int PreEp[MaxDiskNum];  //記錄放在同一個硬碟的前一部動畫
int *Heap_pos=&PreEp[0];//映射這顆硬碟在Heap的哪個位置, Heap位置介於1~M, 0代表不存在Heap
int N, M, HeapNum;

void Heap_swap(int a, int b){ //交換兩個Heap的node, 而且映射的位置也要交換
  Heap_pos[ Heap[a].disk ]=b, Heap_pos[ Heap[b].disk ]=a;
  tmp=Heap[a], Heap[a]=Heap[b], Heap[b]=tmp;
}
void Heap_up(int now){ //根據現在位置和他的父節點比較,注意父節點不能小於1
  for(int pre=now>>1; pre>=1 and Heap[pre].next<Heap[now].next; now=pre,  pre=pre>>1)
    Heap_swap(now,pre);
}
void Heap_down(int now){ //根據現在位置和他的較大子節點比較,注意子節點不能超過HeapNum
  for(int nxt=now<<1; nxt<=HeapNum ; now=nxt,  nxt=nxt<<1){ //預設是左子節點
    if(nxt<HeapNum and Heap[nxt+1].next>Heap[nxt].next)  nxt++; //右子節點存在且大於左子節點,選右
    if(Heap[now].next>=Heap[nxt].next)  break; //現在和較大的比較看可不可以交換
    Heap_swap(now,nxt);
  }
}
void Heap_pop(){
  Heap_swap(1,HeapNum); //先交換...當初debug時沒注意到
  Heap_pos[ Heap[HeapNum].disk ]=0; //把HeapNum那個位置的硬碟映射位置改為0,代表沒接在USB上
  HeapNum--;  //縮小範圍, 做Heap_down時避免超過
  Heap_down(1); //往下挑戰
}
void Heap_push(USB now){
  HeapNum++;
  Heap[HeapNum]=now; //存到HeapNum的位置
  Heap_pos[now.disk]=HeapNum;//改動那顆硬碟的映射位置到HeapNum
  Heap_up(HeapNum); //根據位置往上挑戰
}
int main(){
  int T, times, idx;

  cin>>T;
  while(T--){
    cin>>N>>M;
    // 給定硬碟號碼, 回傳上一次的動畫號碼
    memset(PreEp,0xff,sizeof(PreEp));
    for(int i=0;i<N;i++){
      cin>>E[i].disk, E[i].next=INF;
      if(PreEp[E[i].disk]>=0)
        E[ PreEp[E[i].disk] ].next=i;
      PreEp[E[i].disk]=i;
    }
    memset(PreEp,0,sizeof(PreEp));
    // 先把M個USB的空缺插滿
    for(idx=0, HeapNum=0; idx<N and HeapNum<M; idx++)
      if(Heap_pos[ E[idx].disk ]) //已經接在USB上面,根據映射位置更新Heap[].next,往上挑戰
        Heap[ Heap_pos[ E[idx].disk ]].next=E[idx].next,
        Heap_up(Heap_pos[ E[idx].disk ]);
      else //不存在USB上面,但USB還有空缺可以插就直接插上去
        Heap_push( {E[idx].disk,E[idx].next} );
    // USB已經全滿, 要置換Heap[1]
    for(times=0;idx<N;idx++){ // 把times初始化
      if(Heap_pos[ E[idx].disk ]) //已經接在USB上面,根據映射位置更新Heap[].next,往上挑戰
        Heap[ Heap_pos[ E[idx].disk ]].next=E[idx].next,
        Heap_up(Heap_pos[ E[idx].disk ]);
      else //USB已滿且要插入的硬碟沒接USB上,先做pop()再插入,並記錄次數+1
        times++,
        Heap_pop(),
        Heap_push( {E[idx].disk,E[idx].next} );
    }
    cout<<times<<endl;
  }
}
/*
20 5
1 2 3 4 5 4 3 2 6 7 8 9 8 7 6 11 12 13 1 2
ANS=8
*/