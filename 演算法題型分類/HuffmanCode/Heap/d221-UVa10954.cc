// HeapSort實作
#include<iostream>
using namespace std;
#define MaxNum 5002

int heapN;
long n[MaxNum];
void scanLong(long &x){ char c; for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0'); }
long heap_pop(void){
  long out=n[1];
  n[1]=n[heapN--];
  int idx=1,  nxt;
  while(true){
    nxt=idx;
    int l=2*idx;
    if(l<=heapN and n[l]<n[nxt])  nxt=l;
    int r=l+1;
    if(r<=heapN and n[r]<n[nxt])  nxt=r;
    if(idx==nxt)
      break;
    else{
      int tmp=n[idx]; n[idx]=n[nxt]; n[nxt]=tmp; idx=nxt;
    }
  }
  return out;
}
void heap_push(long x){
  n[++heapN]=x;
  for(int idx=heapN, nxt=idx/2; n[idx]<n[nxt]; idx=nxt, nxt=idx/2){
    int tmp=n[idx]; n[idx]=n[nxt];  n[nxt]=tmp;
  }
}
int main(void){

  for(long N, x;  true; ){
    scanLong(N);
    if(!N) break;
    n[0]=heapN=0;
    for(int i=1;i<=N;i++)
      scanLong(x), heap_push(x);
    long total=0;
    while(heapN>1){
      long x=heap_pop(), y=heap_pop();
      total+=(x+y), heap_push(x+y);
    }
    printf("%lu\n",total);
  }
}