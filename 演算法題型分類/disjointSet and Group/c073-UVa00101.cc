// 簡單模擬：題目已經說明４個操作的定義
// 但題目沒有說的是積木Ａ不一定會在Ａ的位置，代表需要紀錄積木Ａ在哪個位置
// 會用到就是DisjointSet中『群』的概念

#include<bits/stdc++.h>
using namespace std;
#define MAXN 25

int block[MAXN][MAXN];
int group[MAXN];
int len[MAXN];
int N, now, ele;

// 把積木Ｐ上面的都移除：從末端開始移除積木
inline void RemoveBlock(int p){
  now=group[p]; // 先抓到要移除的積木目前在哪一疊積木中
  for(int i=len[now]-1; block[now][i]!=p; i--,len[now]--)
    ele=block[now][i], // 目前搬動的積木號碼
    block[ele][len[ele]++]=ele, // 將目前積木『放回』原先的位置
    group[ele]=ele; // 更新屬於的群組
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  while(cin>>N){
    string act, conjunction;
    int from, to;
    // 初始化
    for(int i=0;i<N;i++)
      block[i][0]=i,
      len[i]=1,
      group[i]=i;

    while(cin>>act and act!="quit"){
      cin>>from>>conjunction>>to;
      if( group[from]==group[to] ) continue; //兩塊積木在同一堆積木中，那麼這樣的動作算是不合法的
      if(act=="move"){
        RemoveBlock(from);
        if(conjunction=="onto")
          RemoveBlock(to);
        // 把積木Ａ放到積木Ｂ上面
        block[group[to]][len[group[to]]++]=from,
        len[group[from]]--,
        group[from]=group[to];
      }
      else{ // pile
        if(conjunction=="onto")
          RemoveBlock(to);
        int tag, nowf=group[from], nowt=group[to], L=len[nowf];
        for(tag=len[nowf]-1; block[nowf][tag]!=from; tag--);
        for(int i=tag; i<len[nowf]; i++,L--)
          ele=block[nowf][i],
          block[nowt][len[nowt]++]=ele,
          group[ele]=nowt;
        len[nowf]=L;
      }
    }
    // output
    for(int i=0;i<N;i++){
      cout<<i<<':';
      for(int j=0;j<len[i];j++)
        cout<<' '<<block[i][j];
      cout<<endl;
    }
  }
}
/*
10
move 9 onto 1
move 8 over 1
move 7 over 1
move 6 over 1
pile 8 over 6
pile 8 over 5
move 2 over 1
move 4 over 9
quit
==
4
pile 0 over 1
pile 2 over 3
move 1 onto 3
quit
*/