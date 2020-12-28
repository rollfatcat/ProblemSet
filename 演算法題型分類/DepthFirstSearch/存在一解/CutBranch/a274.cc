// 題目要求：現在這個數字必須是左側兩個數字的和或是乘積的倍數
// DFS()找到一組解後就停止

#include<bits/stdc++.h>
using namespace std;

int N;
int num[10];
long bag[10];
bool use[10];

bool Trail(int bag_num){
  if(bag_num==N){ // 選滿N個
    for(int i=0;i<N;i++)
      cout<<bag[i]<<" ";
    cout<<endl;
    return true;
  }
  for(int i=0;i<N;i++)
    if(!use[i] and (bag_num<2 or bag[bag_num-2]*bag[bag_num-1]%num[i]==0 or (bag[bag_num-2]+bag[bag_num-1])%num[i]==0)){
      bag[bag_num]=num[i],
      use[i]=1;
      if(Trail(bag_num+1))
        return true;
      use[i]=0;
    }
  return false;
}
int main(){
  while(scanf("%d",&N)!=EOF){
    for(int i=0;i<N;i++)
      scanf("%d",&num[i]);
    sort(num,num+N);
    memset(use,0,sizeof(use));
    if(!Trail(0))
      cout<<"No"<<endl;
  }
}