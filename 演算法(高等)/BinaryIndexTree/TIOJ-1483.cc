/* 設每個點的 DP 值代表從左上角走到這個點，且有取這個點的方法數，
 * 那麼 DP[x][y]=sum{ DP[i][j], 1<=i<=x, 1<=j<=y, a[i][j]<a[x][y] }，
 * 其中 a 是題目給的陣列。所以可以用和『TIOJ 1266』的方法，由值小的做到值大的，
 * 每次需要修改一個點的值還有查詢二維的前綴和， 所以可以用二維的BIT做。
 * 另外這題比較不一樣的是不能直接照順序做，要先把同樣值的格子一次查詢完再一次修改。
 */

#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001
#define MOD 1000000007
#define lowbit(x) (x&-x)

int R, C, maxv;
int BIT[MAXN][MAXN];
int DP[MAXN][MAXN];
struct NODE{
  short x, y;
  NODE(int a=0,int b=0):x(a),y(b){}
};
vector<NODE> v[MAXN];

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
int main(){
  int caseT, x;
  scanf("%d",&caseT);
  while(caseT--){
    for(int i=0;i<=1000;i++)
      v[i].clear();
    scanf("%d %d",&R,&C);
    for(int i=1;i<=R;i++)
      for(int j=1;j<=C;j++){
        scanf("%d",&x),
        v[x].push_back( NODE(i,j) ),
        maxv=max(maxv,x);
      }
    memset(BIT,0,sizeof(BIT));
    for(int nowv=0;nowv<=maxv;nowv++){
      for(NODE j:v[nowv])
        DP[j.x][j.y]=1+query(j.x,j.y);
      for(NODE j:v[nowv])
        update(j.x,j.y,DP[j.x][j.y]);
    }
    int sum=0;
    for(int i=1;i<=R;i++)
      for(int j=1;j<=C;j++)
        sum=(sum+DP[i][j])%MOD;
    printf("%d\n",sum);
  }
}