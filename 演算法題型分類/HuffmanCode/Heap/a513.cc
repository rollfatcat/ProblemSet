// MaxHeap實作(標準模板題)
#include<iostream>
using namespace std;

int HeapN, Heap[30001];
void HeapPush(int x);
int HeapPop();
int main(){

  int T, n, m;
  scanf("%d",&T);
  for(int caseN=1;caseN<=T;caseN++){
    scanf("%d %d",&n,&m);
    HeapN=0;
    for(int x;n--;)
      scanf("%d",&x), HeapPush(x);
    printf("Case %d:\n",caseN);
    for(int act,x; m--;){
      scanf("%d",&act);
      if(act==1)  scanf("%d",&x), HeapPush(x);
      else{
        x=HeapPop();
        if(x>=0) printf("Max: %d\n",x);
        else puts("It's empty!");
      }
    }
    if(!HeapN) puts("It's empty!");
    while(HeapN)
      printf("%d ",HeapPop());
    puts("");
  }
}
void HeapPush(int x){
  Heap[++HeapN]=x;
  for(int tmp,now=HeapN; now>1 and Heap[now]>Heap[now>>1];now>>=1)
    tmp=Heap[now], Heap[now]=Heap[now>>1], Heap[now>>1]=tmp;
}
int HeapPop(){
  if(!HeapN)  return -1;
  Heap[0]=Heap[1],Heap[1]=Heap[HeapN--];
  for(int now=1,nxt=2,tmp; nxt<=HeapN; now=nxt,nxt=nxt<<1){ //預設是左子節點
    if(nxt<HeapN and Heap[nxt+1]>Heap[nxt])  nxt++; //右子節點存在且大於左子節點,選右
    if(Heap[now]>=Heap[nxt])  break; //現在和較大的比較看可不可以交換
    tmp=Heap[now], Heap[now]=Heap[nxt], Heap[nxt]=tmp;
  }
  return Heap[0];
}