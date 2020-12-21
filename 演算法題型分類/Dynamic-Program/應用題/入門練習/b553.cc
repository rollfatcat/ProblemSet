// 數論的3Ｎ+1問題，可以用DFS算迭代次數並且把算過得用陣列存起來
// 注意雖然輸入的範圍只落在30,000以內，但迭代的過程中數字可能會超過30,000
// 只有落在範圍內的數字才存，且讀取陣列時也要判斷是否在範圍內
#include<bits/stdc++.h>
using namespace std;

const int MAXN=30001;
int path[MAXN];
int DFS(int x){
  if(MAXN>x and path[x] or x==1)
    return path[x];
  int v=(x&1)? DFS(3*x+1)+1: DFS(x>>1)+1;
  if(MAXN>x) path[x]=v;
  return v;
}
int main(){
  for(int n;scanf("%d",&n)!=EOF;)
    printf("%d\n",DFS(n));
}