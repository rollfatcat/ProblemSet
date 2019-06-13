// 演算法：SCC(強聯通元件)
// 題解：https://m80126colin.github.io/blog/articles/%E7%A8%8B%E5%BC%8F%E7%A2%BC/zj/zj-d197-code/
/* 教學文：http://alrightchiu.github.io/SecondRound/graph-li-yong-dfshe-bfsxun-zhao-connected-component.html
 *
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=100001;
int Nnode, Nedge;
bool vis[maxN];
vector<int> e[maxN];
inline bool scanInt(int &x){
  char c;
  while((c=getchar())==' ' or c=='\n');
  for(x=c-'0';(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  return c!=EOF;
}

int main(){
  int caseN;
  for(scanInt(caseN); caseN--; ){
    scanInt(Nnode), scanInt(Nedge);
    for(int i=1;i<=Nnode;i++)
      e[i].clear(), vis[i]=0;
    for(int a,b;Nedge--;)
      scanInt(a),
      scanInt(b),
      e[a].push_back(b);

    printf("%d\n",N);
  }
}