// HeapSort實作
#include<iostream>
using namespace std;
#define MaxNum 1000

int n[MaxNum+1], N;
int compare(const void*a,const void*b){ return *(int*)a-*(int*)b; }
int heap_pop(void){
  int out=n[1];
  n[1]=n[N--];
  int idx=1,  nxt;
  while(true){
    nxt=idx;
    int l=2*idx;
    if(l<=N and n[l]<n[nxt])  nxt=l;
    int r=l+1;
    if(r<=N and n[r]<n[nxt])  nxt=r;
    if(idx==nxt)
      break;
    else{
      int tmp=n[idx]; n[idx]=n[nxt]; n[nxt]=tmp; idx=nxt;
    }
  }
  return out;
}
void heap_push(int x){
  n[++N]=x;
  for(int idx=N, nxt=idx/2; n[idx]<n[nxt]; idx=nxt, nxt=idx/2){
    int tmp=n[idx]; n[idx]=n[nxt];  n[nxt]=tmp;
  }
}
int main(void){
  cin>>N;
  n[0]=0;
  for(int i=1;i<=N;i++)
    cin>>n[i];
  qsort(n,N+1,sizeof(n[0]),compare);
  long long int total=0;
  while(N>1){
    int x=heap_pop();
    int y=heap_pop();
    total+=(x+y);
    heap_push(x+y);
    //for(int i=1;i<=N;i++)
    //  cout<<' '<<n[i];
    //cout<<endl;
  }
  cout<<total<<endl;
}