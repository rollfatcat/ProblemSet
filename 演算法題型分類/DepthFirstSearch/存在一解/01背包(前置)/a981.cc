
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 30

int n, total_w, cnt;
int num[MAXN];
int Pick[MAXN];
void DFS(int now,int PickNum){
  if(total_w==0){
    cnt++;
    for(int i=0;i<PickNum;i++)
      cout<<Pick[i]<<' ';
    cout<<'\n';
  }
  if(now==n)
    return;
  for(int i=now;i<n;i++)
    if(total_w>=num[i]){
      Pick[PickNum]=num[i];
      total_w-=num[i];
      DFS(i+1,PickNum+1);
      total_w+=num[i];
    }
}

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  while(cin>>n>>total_w){
    for(int i=0;i<n;i++)
      cin>>num[i];
    sort(num,num+n);
    cnt=0;
    DFS(0,0);
    if(cnt==0)
      cout<<-1<<endl;
  }
}