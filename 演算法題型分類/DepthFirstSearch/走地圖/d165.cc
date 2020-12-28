#include<iostream>
using namespace std;
#define MaxN 100

int m, n, val;
bool vis[MaxN][MaxN];
int  map[MaxN][MaxN];
inline bool ReadInt(int *x);
inline void PrintInt(int x){
  if(x>9) PrintInt(x/10);
  putchar(x%10+'0');
}
void DFS(int y, int x){
  if( y<0 or m<=y or x<0 or n<=x or vis[y][x]==0 )
    return;
  vis[y][x]=0;
  val+=map[y][x];
  DFS(y-1,x);
  DFS(y,x-1);
  DFS(y+1,x);
  DFS(y,x+1);
}

int main(){
  while(ReadInt(&m) and ReadInt(&n) and m and n){
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        ReadInt(&map[i][j]), vis[i][j]=(map[i][j]>0);
    int cnt=0, max=0;
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        if(vis[i][j]){
          cnt++;
          val=0;
          DFS(i,j);
          if(max<val)
            max=val;
        }
    PrintInt(cnt), puts("");
    PrintInt(max), puts("");
  }

}
inline bool ReadInt(int *x){
  static char c, neg;
  while((c=getchar())<'-')    {if(c == EOF) return 0;}
  neg=(c=='-')?-1:1;
  *x=(neg==1)?(c-'0'):0;
  while((c=getchar())>='0')
      *x=(*x<<3)+(*x<<1)+c-'0';
  *x*=neg;
  return 1;
}