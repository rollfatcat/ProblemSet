// 枚舉每樣物品放或不放的選項
#include<iostream>
#include<algorithm>
using namespace std;
#define MaxN 101
#define MaxW 10001

int total_w, len, total_v, max_v;
int v[MaxN], w[MaxN];

void DFS(int now){
  if(now==len){
    if(max_v<total_v)
      max_v=total_v;
    return;
  }
  for(int i=now;i<len;i++)
    if(total_w>=w[i]){
      total_w-=w[i];
      total_v+=v[i];
      DFS(i+1);
      total_w+=w[i];
      total_v-=v[i];
    }
}
int main(){
  for(int caseNum=1000; caseNum; caseNum--){
    cin>>len;
    for(int i=0;i<len;i++)
      cin>>w[i]>>v[i];
    cin>>total_w;
    total_v=max_v=0;
    DFS(0);
    cout<<max_v<<endl;
  }
}