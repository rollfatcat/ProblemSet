/* DFS＋Adjancy List：統計全部的節點高度和輸出 Root
 * 但這一題的地圖是『樹』的結構
 * 題目保證：只存在一個Root且每個節點只有一個父節點
 * 換句話說，沒有父節點的一定是Root，抓出Root後做DFS拜訪整棵樹並回傳(最高)高度即可
 * 題目有定義『高度』：離葉節點最長的距離(葉節點高度=0)
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=100001;
int N;
long sumH;
vector<int> edge[MAXN];
bool NotRoot[MAXN]={};

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int DFS(int now){
  int nowH=0;
  for(int i=0;i<edge[now].size();i++)
    nowH=max(nowH,DFS(edge[now][i])+1);
  sumH+=nowH;
  return nowH;
}
int main(){
  int num, x, idx;

  scanInt(N);
  for(int i=1;i<=N;i++){
    scanInt(num);
    for(int j=1;j<=num;j++)
      scanInt(x),
      NotRoot[x]=1,
      edge[i].push_back(x);
  }
  for(idx=1;NotRoot[idx];idx++);
  sumH=0;
  DFS(idx);
  printf("%d\n%ld\n",idx,sumH);
}
/*
7
0
2 6 7
2 1 4
0
2 3 2
0
0
*/