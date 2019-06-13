/* 雷同：TIOJ-1483，都是要求『嚴格遞增』的路線總數
 * 所有的輸入值都是非負整數且不超過1000。
 * 根據輸入的數值丟到對應的bucket，一次查詢完之後再一次更新。
 */
#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&-x)
#define MOD 1000000007

int R, C;
int BIT[1001][1001];
int DP[1001][1001];
struct NODE{
  short x,y;
  NODE(int a=0,int b=0):x(a),y(b){}
};
vector<NODE> v[1001];

void update(int x,int y,int val){
  for(int i=x;i<=R;i+=lowbit(i))
    for(int j=y;j<=C;j+=lowbit(j))
      BIT[i][j]=(BIT[i][j]+val)%MOD;
}
inline int query(int x,int y,int out=0){
  for(int i=x;i;i-=lowbit(i))
    for(int j=y;j;j-=lowbit(j))
      out=(out+BIT[i][j])%MOD;
  return out;
}
inline void scanInt(int &x){
  char c;
  while((c=getchar())==' ' or c=='\n');
  for(x=c-'0';(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
}
int main(){
  int caseT, maxv;
  scanInt(caseT);
  while(caseT--){
    scanInt(R);
    scanInt(C);
    for(int i=0;i<=1000;i++)
      v[i].clear();
    maxv=0;
    for(int i=1;i<=R;i++)
      for(int x,j=1;j<=C;j++)
        scanInt(x),
        maxv=max(maxv,x),
        v[x].push_back( NODE(i,j) );

    //
    memset(BIT,0,sizeof(BIT));
    for(int nowv=0;nowv<=maxv;nowv++){
      for(NODE j:v[nowv])
        DP[j.x][j.y]=1+query(j.x,j.y);
      for(NODE j:v[nowv])
        update(j.x,j.y,DP[j.x][j.y]);
    }
    printf("%d\n",query(R,C));
  }
}