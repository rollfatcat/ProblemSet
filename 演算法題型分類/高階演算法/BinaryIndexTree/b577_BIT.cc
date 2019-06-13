// 動態規劃求區段不重疊的最大價值總和：O(N㏒N)版本17ms
#include<bits/stdc++.h>
using namespace std;
#define MAXN 32768
#define lowbit(x) (x&-x)

struct LINE{
  int st, ed, v;
  bool operator<(const LINE &rhs)const{ return(st==rhs.st)?(ed<rhs.ed):(st<rhs.st); }
}line[10000];
int BIT[MAXN];

inline void update(int x,int v){
  for(;x<MAXN;x+=lowbit(x))
    BIT[x]=max(BIT[x],v);
}
inline int query(int x,int v=0){
  for(;x;x-=lowbit(x))
    v=max(BIT[x],v);
  return v;
}

int main(){
  int caseT, Nline;
  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d",&Nline);
    for(int i=0;i<Nline;i++)
      scanf("%d%d%d",&line[i].st,&line[i].ed,&line[i].v);
    sort(line,line+Nline);
    memset(BIT,0,sizeof(BIT));
    int maxv=0;
    for(int i=0;i<Nline;i++){
      line[i].v+=query(line[i].st),
      update(line[i].ed,line[i].v),
      maxv=max(maxv,line[i].v);
    }
    printf("%d\n",maxv);
  }
}