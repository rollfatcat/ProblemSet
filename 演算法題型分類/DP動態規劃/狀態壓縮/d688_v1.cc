// 動態規劃＋狀態壓縮：狀態轉移
// 現在這個狀態是有效的時候，就枚舉每個存在集合中的點且有條邊連到一個不存在集合中的點
// 極限測資：20*20*(1<<20) => 1.3s

#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (-x&x)

const int MAXN=20;
vector<short> Edge[MAXN];
bool status[1<<MAXN];

int main(){
  int Vnum, Enum;
  while(scanf("%d %d",&Vnum,&Enum) and Vnum){
    int maxs=1<<Vnum;
    for(int nows=1;nows<maxs;nows++)// 避開用memset()，陣列空間過大
      status[nows]=0;
    for(int i=0;i<Vnum;i++)
      Edge[i].clear(),
      status[1<<i]=1;  // 單點狀態設定為 1
    for(int a,b;Enum--;)
      scanf("%d %d",&a,&b), a--, b--,
      Edge[a].push_back(b),
      Edge[b].push_back(a);

    for(int nows=1;nows<maxs;nows++) // 枚舉全部的狀態
      if(status[nows])
        for(int tag,tmps,outs=nows; outs; outs^=(1<<tag)){
          tmps=lowbit(outs),
          tag=__lg(tmps);
          for(int rhs:Edge[tag])
            if( (nows&(1<<rhs))==0 ) // tag在集合中但rhs不在集合中 且 存在一條邊(tag,rhs)可以狀態轉移
              status[nows|(1<<rhs)] |= status[nows];
        }
    int cnt=0;
    for(int i=0;i<maxs;i++)
      cnt+=status[i];
    printf("%d\n",cnt);
  }
}
/*
7 10
2 5
4 7
2 4
6 2
7 3
7 1
6 5
7 5
1 2
5 3
===
84
*/