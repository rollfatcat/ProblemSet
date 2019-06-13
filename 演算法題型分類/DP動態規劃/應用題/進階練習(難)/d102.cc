//首先，要能夠構成一个簡單多邊形需要滿足兩個條件：
//  (1) 至少有3條邊
//  (2) 最長邊的長度小於其餘所有邊長度的和
// 加強版：d763

#include<bits/stdc++.h>
using namespace std;

int edge[102];
int Nedge, cnt;

void DFS(int remLen,int ed){
  // 假設目前這個邊的邊長已經多出需要補足的長度時，這個邊之前的邊都是可選或不選的兩種選項
  for(;ed>=0 and edge[ed]>remLen;ed--)
    cnt+=1<<ed;
  // 假設目前這個邊的邊長仍不足需要補足的長度時，強制從目前的範圍選擇一個邊後遞迴處理
  for(;ed>0;ed--)
    DFS(remLen-edge[ed],ed-1);
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  string line;
  while(getline(cin,line)){
    stringstream ss(line);
    for(Nedge=0;ss>>edge[Nedge];Nedge++);
    if(Nedge==1 and edge[0]==0) break;

    sort(edge,edge+Nedge);
    cnt=0;
     // 枚舉兩個邊(最長和次長)，第三個以上的邊用DFS
    for(int i=2; i<Nedge; i++)
      for(int j=i-1; j>0; j--)
        DFS(edge[i]-edge[j],j-1);
    cout<<cnt<<'\n';
  }
}
// 3 4 5 6 9