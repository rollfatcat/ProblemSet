#include<iostream>
#include<cmath>
using namespace std;

int n, cnt, op[20];
long long int bound;
char sym[3]={' ','+','-'};
void DFS(long long int StackNum, long long int Num, int now){
  if(Num>bound or Num<-bound)  return;
  if(now==(n+1)){
    if((StackNum+Num)==0){
      cout<<1;
      for(int i=2;i<=n;i++)
        cout<<sym[op[i]]<<i;
      cout<<endl;
    }
    return ;
  }
  op[now]=0;
  if(now>=10) DFS(StackNum,100*Num+((Num>0)?now:-now),now+1);
  else  DFS(StackNum,10*Num+((Num>0)?now:-now),now+1);
  op[now]=1,  DFS(StackNum+Num,now,now+1);
  op[now]=2,  DFS(StackNum+Num,-now,now+1);
}
int main(){
  while(cin>>n)
    bound=pow(10,(int)n/2),
    DFS(0,1,2);
}