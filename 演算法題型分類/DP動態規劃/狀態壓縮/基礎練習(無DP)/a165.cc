// 狀態壓縮的寫法
#include<iostream>
using namespace std;

int N=-1;
void DFS(int num,int nowS,int L){
  if(L==10){ N=num; return; }
  int nState, nPut, number, nPos;
  for(nState=nowS; nState; nState^=nPut){
    nPut=nState&-nState,
    number=10*num+__builtin_ffs(nPut);
    if(number%L==0)
      DFS(number,nowS^nPut,L+1);
  }
}
int main(){
  DFS(0,(1<<9)-1,1);
  cout<<N<<endl;
}