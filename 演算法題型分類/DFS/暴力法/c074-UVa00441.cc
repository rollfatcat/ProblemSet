// 不用剪枝加速, 注意送UVA的 Presentation Error
#include<iostream>
using namespace std;
#define MaxN 12

int num[MaxN], k, bag[6];
void DFS(int now, int st){
  if(now==6){
    cout<<bag[0];
    for(int i=1;i<6;i++)
      cout<<' '<<bag[i];
    cout<<endl;
    return;
  }
  // 剪枝的寫法
  for(int i=st;i<=k-(6-now);i++)
    bag[now]=num[i], DFS(now+1,i+1);
}
int main(){
  for(int t=0;cin>>k and k;t++){
    if(t>0)
      cout<<endl;
    for(int i=0;i<k;i++)
      cin>>num[i];
    DFS(0,0);
  }
}