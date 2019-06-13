// 動態規劃求區段不重疊的最大價值總和：O(n^2)版本 => 0.5s
#include<bits/stdc++.h>
using namespace std;
#define MAXN 32768
#define lowbit(x) (x&-x)

struct LINE{
  int st, ed, v;
  bool operator<(const LINE &rhs)const{ return(st==rhs.st)?(ed<rhs.ed):(st<rhs.st); }
}line[10000];

int main(){
  int caseT, Nline;
  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d",&Nline);
    for(int i=0;i<Nline;i++)
      scanf("%d%d%d",&line[i].st,&line[i].ed,&line[i].v);
    sort(line,line+Nline);
    int maxv=0;
    for(int i=0;i<Nline;i++){
      int tmpv=0;
      for(int j=i-1;j>=0;j--)
        if(line[i].st>=line[j].ed)
          tmpv=max(tmpv,line[j].v);
      line[i].v+=tmpv;
      maxv=max(maxv,line[i].v);
    }
    printf("%d\n",maxv);
  }
}