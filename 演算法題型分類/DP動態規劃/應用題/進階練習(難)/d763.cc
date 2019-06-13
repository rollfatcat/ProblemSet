// 這題和 d102 的差異是真正要輸出方法數(不取模)
// 觀察方法數的累計可以發現其實不需要大數處理改為__int128即可

#include<bits/stdc++.h>
using namespace std;

int Nedge, edge[102];
__int128 cnt;

void DFS(int remLen,int ed){
  // 假設目前這個邊的邊長已經多出需要補足的長度時，這個邊之前的邊都是可選或不選的兩種選項
  for(;ed>=0 and edge[ed]>remLen;ed--)
    cnt+=(__int128)1<<ed;
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
    //cout<<cnt<<'\n';
    string ans_ss;
    while(cnt)
      ans_ss=(char)(cnt%10+'0')+ans_ss, cnt/=10;
    cout<<ans_ss<<endl;
  }
}
// 3 4 5 6 9