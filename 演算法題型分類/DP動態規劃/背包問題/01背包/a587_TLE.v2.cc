// 枚舉每樣物品放或不放的選項
// Cut-Branch：排序後把不可能的提早
#include<iostream>
#include<algorithm>
using namespace std;
#define MaxN 101
#define MaxW 10001

int total_w, len, total_v, max_v;
struct Item{ int v, w;} item[MaxN];
bool compare(Item a, Item b){ return (a.w==b.w)?(a.v<b.v):(a.w<b.w); }

void DFS(int now){
  if(now==len or total_w==0){ //沒東西可以選或是已經裝滿(剩餘重量=0)
    if(max_v<total_v)
      max_v=total_v;
    return;
  }
  for(int i=now;i<len and total_w>=item[i].w;i++){
    total_w-=item[i].w;
    total_v+=item[i].v;
    DFS(i+1);
    total_w+=item[i].w;
    total_v-=item[i].v;
  }
}
int main(){
  for(int caseNum=1000; caseNum; caseNum--){
    cin>>len;
    for(int i=0;i<len;i++)
      cin>>item[i].w>>item[i].v;
    cin>>total_w;
    sort(item,item+len,compare);

    total_v=max_v=0;
    DFS(0);
    cout<<max_v<<endl;
  }
}