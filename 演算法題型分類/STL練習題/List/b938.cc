// 殺掉 號碼k的下一個人 => 陣列模擬 LinkList (0.3s/9MB)
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1000001;
bool dead[MAXN]={1}; //映射表:確認某個號碼是否活著
struct NODE{
  int nxt,val;
}node[MAXN];
inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  int N, Q, now;
  scanInt(N),
  scanInt(Q);
  for(int i=1;i<N;i++)
    node[i]={i+1,i};
  node[N]={0,N};
  while(Q--){
    scanInt(now);
    // 不合法 : (1)該號碼已經死亡 (2)這個號碼後面已經沒有生還者
    if(dead[now] or dead[node[now].nxt] ){ puts("0u0 ...... ?"); continue; }
    int kill=node[now].nxt;
    dead[kill]=1;
    node[now].nxt=node[kill].nxt;
    printf("%d\n",kill);
  }
}