// 不一定會用到Queue的BFS
#include<iostream>
using namespace std;

int N, Num[1000002];
int *num=&Num[1];
int BFS(int x){
  int i=1;
  while(num[x]<num[x-i] and num[x]<num[x+i])
    i++;
  return i;
}
int main(){
  cin>>N;
  num[-1]=num[N]=-1;
  for(int i=0;i<N;i++)
    cin>>num[i];
  int cnt=0;
  for(int i=0;i<N;i++)
    cnt+=BFS(i);
  cout<<cnt<<endl;
}