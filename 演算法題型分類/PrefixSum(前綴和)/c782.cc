// 連續區間和
// 觀察測資數量可以發現：無法枚舉的方式()
// 累加時可以發現：可以用前綴和計算(不要一個一個互乘後累加)

#include<iostream>
using namespace std;

struct Node{
  int pos, pre;
  long sum;
}N[2000001];

int main(){
  int T, n, k, v;
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  N[0].pos=0, N[0].sum=0;
  for(cin>>T; T--; ){
    cin>>n>>k;
    int idx=1;
    for(int i=1;i<=n;i++){
      cin>>N[i].pos;
      for(;(N[idx].pos+k)<N[i].pos;idx++);
      N[i].pre=idx;
    }
    long ans=0;
    for(int i=1;i<=n;i++)
      cin>>N[i].sum,
      ans+=N[N[i].pre-1].sum*N[i].sum,
      N[i].sum+=N[i-1].sum;
    cout<<ans<<endl;
  }
}