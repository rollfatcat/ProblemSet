// 窮舉所有的運算元和數字
#include<iostream>
#include<cstring>
using namespace std;

bool hasAns, use[5];
int num[5];
void DFS(int n,int len){
  if(len==5){ if(n==23) hasAns=true; return; }
  for(int i=0;i<5;i++)
    if(!use[i])
      use[i]=1,
      DFS(n+num[i],len+1),
      DFS(n-num[i],len+1),
      DFS(n*num[i],len+1),
      use[i]=0;
}
int main(){
  while(cin>>num[0]){
    cin>>num[1]>>num[2]>>num[3]>>num[4];
    if(num[0]+num[1]+num[2]+num[3]+num[4]==0)
      break;
    hasAns=false;
    memset(use,0,sizeof(use));
    for(int i=0;i<5;i++)
      use[i]=1,
      DFS(num[i],1),
      use[i]=0;
    cout<<((hasAns)?"Possible":"Impossible")<<endl;
  }
}