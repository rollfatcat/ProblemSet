// 練習走DFS的簡單題
#include<iostream>
#include<vector>
using namespace std;
#define MaxN 1000001

vector<bool>isSelf(MaxN,true);
void DFS(int x){
  if(x>=MaxN or !isSelf[x])  return;
  isSelf[x]=false;
  int nxt=x;
  while(x)
    nxt+=x%10,  x/=10;
  DFS(nxt);
}
int main(){
  for(int i=1;i<MaxN;i++)
    if(isSelf[i])
      cout<<i<<endl,  DFS(i);
}