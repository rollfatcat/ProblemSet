// DFS暴搜就好
#include<iostream>
using namespace std;

int N=-1;
bool use[10]={1,0,0,0,0,0,0,0,0,0};
void DFS(int num,int L){
  if(L==10){ N=num; return; }
  for(int i=9;i>0;i--)
    if(!use[i]){
      int n=10*num+i;
      if(n%L==0)
        use[i]=1,
        DFS(n,L+1),
        use[i]=0;
    }
}
int main(){
  DFS(0,1);
  cout<<N<<endl;
}